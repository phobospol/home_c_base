#include <stdio.h>
#include <string.h>

// В файле input.txt необходимо удалить все лишние пробелы (в начале предложения и сдвоенные пробелы). Для решения задачи разработать функцию. Результат записать в output.txt.

#define MAX_LENGTH 1000

// Функция для удаления лишних пробелов: в начале строки и сдвоенных пробелов
void remove_extra_spaces(char *str) {
    char result[MAX_LENGTH];  // Буфер для результата
    int i = 0, j = 0;      // Индексы: i — для исходной строки, j — для результата
    int prev_is_space = 0;  // Флаг: был ли предыдущий символ пробелом

    // Пропускаем пробелы в начале строки
    while (str[i] == ' ') {
        i++;
    }

    // Обрабатываем оставшуюся часть строки
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            // Добавляем пробел только если предыдущий символ не был пробелом
            if (!prev_is_space) {
                result[j++] = ' ';
                prev_is_space = 1;
            }
        } else {
            // Копируем обычный символ
            result[j++] = str[i];
            prev_is_space = 0;
        }
        i++;
    }

    // Убираем пробел в конце, если он есть
    if (j > 0 && result[j - 1] == ' ') {
        j--;
    }

    // Завершаем строку нулевым терминатором
    result[j] = '\0';

    // Копируем результат обратно в исходную строку
    strcpy(str, result);
}

int main(int argc, char **argv)
{
    FILE *inputfile, *outputfile;
    char sentence[MAX_LENGTH];

    // Открываем файлы
    inputfile = fopen ("input.txt", "r");
    if (inputfile == NULL)
    {
        perror("Could not open input.txt\n");
        fclose (inputfile);
        return 1;
    }
    outputfile = fopen ("output.txt", "w");
    if (outputfile == NULL)
    {
        perror("Could not open output.txt\n");
        fclose (outputfile);
        return 1;
    }
    // Читаем строку из input.txt
    if (fgets (sentence, MAX_LENGTH, inputfile) == NULL)
    {
        perror("File input.txt empty or a reading error occurred\n");
        fclose (inputfile);
        fclose (outputfile);
        return 1;
    }

    // Удаляем символ новой строки, если он есть
    size_t len = strlen (sentence);
    if (len > 0 && sentence [len-1] == '\n')
    {
        sentence [len-1] = '\0';
    }

    // Применяем функцию удаления лишних пробелов
    remove_extra_spaces(sentence);



    // Записываем результат в output.txt
    fprintf(outputfile, "%s\n", sentence);

    // Закрываем файлы
    fclose (inputfile);
    fclose (outputfile);

    return 0;
}
