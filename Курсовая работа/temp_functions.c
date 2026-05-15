#include "temp_functions.h" // Включение заголовочного файла temp_functions.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Подключение библиотеки для проверки символов

/* Функция is_empty_or_comment проверяет, является ли строка пустой или комментарием (начинается с #).
   Если строка начинается с # или состоит из пробелов то возвращает 1, в противном случае - 0. */
static int is_empty_or_comment(const char *line) 
{
    while (*line)
    {
        if (!isspace(*line))
        {
            return (*line == '#');
        }
        line++;
    }
    return 1;
}

/* Функция find_record ищет запись с совпадающей датой и временем. Используется, чтобы не добавлять 
   дубликаты записей (обновляет температуру, если запись уже есть). Возвращает: индекс записи, если найдена; -1 — иначе. */
static int find_record(Record *records, size_t count, Record r)
{
    for (size_t i = 0; i < count; i++)
    {
        if (records[i].year == r.year &&
                records[i].month == r.month &&
                records[i].day == r.day &&
                records[i].hour == r.hour &&
                records[i].minute == r.minute)
        {
            return i;
        }
    }
    return -1;
}

// Функция read_csv читает CSV-файл, заполняет массив records и возвращает количество записей (count)
int read_csv(const char *filename, Record **records, size_t *count)
{
    FILE *file = fopen(filename, "r"); // открывает файл для чтения
    if (!file) // Если файл не найден, perror выведет сообщение об ошибке и возвращается -1
    {
        perror("Error opening file");
        return -1;
    }

    // Динамическое выделение памяти
    size_t capacity = 1000; // первоначально выделяется память для 1000 записей
    *records = malloc(capacity * sizeof(Record)); // malloc возвращает указатель на блок памяти. *records — указатель на массив записей (передаётся как **records, чтобы изменить исходный указатель в main())
    if (!*records) // если памяти недостаточно, — программа закрывает файл, выводит ошибку и возвращает -1
    {
        fclose(file);
        fprintf(stderr, "Error allocating memory\n");
        return -1;
    }

    // Чтение строк из файла
    char line[256]; // создаётся буфер line длиной 256 символов
    int line_num = 0; // создается переменная номера некорректной строки для вывода в сообщении об ошибке 
    *count = 0;

    while (fgets(line, sizeof(line), file)) // считывает строку из файла
    {
        line_num++; // подсчет номера некорректной строки
        line[strcspn(line, "\n")] = 0; // находит позицию символа \n, заменяя его на нулевой символ ('\0'), чтобы убрать перевод строки

        if (is_empty_or_comment(line)) // пропускает пустые строки и строки, начинающиеся с # (комментарии)
            continue;

        // Разбор строки в структуру Record
        Record r;

        if (sscanf(line, "%d;%d;%d;%d;%d;%d",
                   &r.year, &r.month, &r.day,
                   &r.hour, &r.minute, &r.temperature) != 6) // разбирает строку по формату год;месяц;день;час;минута;температура. Если не удалось прочитать 6 значений, строка считается некорректной, и её пропускают
        {
            printf("Format error in line %d: %s\n", line_num, line); 
            continue;
        }

        // Проверка валидности данных
        if (r.year < 1900 || r.year > 3000 ||
                r.month < 1 || r.month > 12 ||
                r.day < 1 || r.day > 31 ||
                r.hour < 0 || r.hour > 23 ||
                r.minute < 0 || r.minute > 59 ||
                r.temperature < -99 || r.temperature > 99) // проверяет, что: год в диапазоне 1900–3000, месяц — 1–12, день — 1–31, час — 0–23, минута — 0–59, температура — -99–99. Некорректные строки пропускаются.
        {
            printf("Invalid data in line %d: %s\n", line_num, line);
            continue;
        }

        // Добавление/обновление записи
        int idx = find_record(*records, *count, r);

        if (idx == -1) // Если запись с такими датой и временем не существует, добавляем её:
        {
            if (*count >= capacity) // Если текущий размер массива (*count) достиг ёмкости (capacity), используем realloc, чтобы увеличить память вдвое
            {
                capacity *= 2; // удваиваем ёмкость
                Record *temp = realloc(*records, capacity * sizeof(Record));
                if (!temp) // ошибка realloc
                {
                    printf("Error reallocating memory\n");
                    free(*records);
                    fclose(file);
                    return -1;
                }
                *records = temp; 
            }
            (*records)[*count] = r; // добавляем запись в конец массива
            (*count)++; // увеличиваем счётчик *count
        }
        else
        {
            (*records)[idx].temperature = r.temperature; // Если запись уже есть, обновляем поле temperature (возможно, данные пришли повторно)
        }
    }

    fclose(file); // закрываем файл
    return 0; // возвращаем 0, сигнализируя об успешном завершении
}

// Функция print_month_stats выводит статистику за заданный месяц
void print_month_stats(Record *records, size_t count, int month)
{
    int sum = 0, min = 100, max = -100, n = 0;

    for (size_t i = 0; i < count; i++) // проходит по всем записям массива, собирает сумму, минимум, максимум для заданного месяца
    {
        if (records[i].month == month)
        {
            int t = records[i].temperature;
            sum += t;
            if (t < min) min = t;
            if (t > max) max = t;
            n++;
        }
    }

    if (n == 0)
        return;

    printf("Statistics for month %d:", month); // выводит обрабатываемый месяц
    printf("  Average is %.2f,", (float)sum / n); // выводит среднюю температуру как sum / n
    printf("  Minimum is %d,", min); // выводит минимальную температуру за месяц 
    printf("  Maximum is %d\n", max); // выводит максимальную температуру за месяц 
}

// Функция print_year_stats выводит статистику за год
void print_year_stats(Record *records, size_t count)
{
    if (count == 0) // если нет записей
    {
        printf("No data\n");
        return;
    }

    int sum = 0, min = 100, max = -100;

    for (size_t i = 0; i < count; i++) // проходит по всем записям массива, собирает сумму, минимум, максимум за год
    {
        int t = records[i].temperature;
        sum += t;
        if (t < min) min = t;
        if (t > max) max = t;
    }

    printf("Year statistics:");
    printf("  Average is %.2f,", (float)sum / count); // выводит среднюю температуру за год как sum / count
    printf("  Minimum is %d,", min); // выводит минимальную температуру за год
    printf("  Maximum is %d\n", max); // выводит максимальную температуру за год 
}
