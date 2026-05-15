#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> // для работы с локализацией
#include "temp_functions.h"

// Функция print_help выводит справку о том, как использовать программу -h — справка, -f — имя файла, -m — месяц
void print_help(const char *program_name)
{
    printf("Multi-module program for reading and statistical analysis of data from temperature sensor CSV files \n");
    printf("Input format: %s\n", program_name);
    printf("              %s [-h]\n", program_name);
    printf("              %s [-f filename.csv]\n", program_name);
    printf("              %s [-f filename.csv] [-m xx]\n", program_name);
    printf("  -h                  Display help message\n");
    printf("  -f filename.csv     Input CSV file\n");
    printf("  -m xx               Specific month statistics (1-12)\n");
}

// Функция parse_int преобразует командную строку str в целое число с помощью функции strtol
int parse_int(const char *str, int *value)
{
    char *end;
    long v = strtol(str, &end, 10); // strtol возвращает число и указатель end на остаток строки

    if (*end != '\0') // Если *end != '\0', значит, строка содержит нечисловые символы (например, "123abc") → возвращает 0 (ошибка).
        return 0;

    *value = (int)v; // иначе записывает значение в *value и возвращает 1
    return 1;
}

int main(int argc, char *argv[])
{
    // Функция setlocale для установки локали "С" для вывода вещественного числа с точкой независимо от настроек ОС
    setlocale (LC_ALL, "C");
    // Инициализация переменных
    char *filename = NULL; // хранит имя CSV-файла
    int month = 0; // хранит номер месяца для детализированной статистики

    // Разбор аргументов командной строки
    for (int i = 1; i < argc; i++) // Цикл проходит по аргументам (начиная с i=1, так как argv[0] — имя программы)
    {
        if (strcmp(argv[i], "-h") == 0) // -h: выводит справку и завершает работу
        {
            print_help(argv[0]);
            return 0;
        }
        else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) // -f: считывает имя файла из следующего аргумента
        {
            filename = argv[++i];
        }
        else if (strcmp(argv[i], "-m") == 0 && i + 1 < argc) // -m: считывает номер месяца, проверяет, что это число от 1 до 12
        {
            if (!parse_int(argv[++i], &month) || month < 1 || month > 12)
            {
                printf("Error: invalid month\n");
                return 1;
            }
        }
        else
        {
            printf("Error in arguments\n"); // если аргументы некорректны, выводит ошибку и завершается
            return 1;
        }
    }

    if (!filename) // Обязательность указания файла. Программа не запустится, если не указан файл (-f)
    {
        printf("No input CSV file specified\n");
        print_help(argv[0]);
        return 1;
    }

    // Чтение CSV-файла
    Record *records = NULL; // инициализирует records
    size_t count = 0; // инициализирует мcount

    if (read_csv(filename, &records, &count) != 0) // Вызывает read_csv, передавая указатель на указатель (&records), чтобы функция могла изменить records в main
    {
        return 1;
    }

    // Проверка наличия данных
    if (count == 0) // Если валидных записей нет, выводит сообщение и освобождает память.
    {
        printf("No valid data\n");
        free(records);
        return 0;
    }

    // Вывод статистики
    if (month) // Если указан месяц (month != 0), выводит статистику только за этот месяц.
    {
        print_month_stats(records, count, month);
    }
    else
    {
        for (int m = 1; m <= 12; m++) // иначе выводит статистику по всем месяцам и годовую.
        {
            print_month_stats(records, count, m);
        }
        print_year_stats(records, count);
    }

    free(records); // в конце освобождает выделенную память с помощью free(records)
    return 0;
}
