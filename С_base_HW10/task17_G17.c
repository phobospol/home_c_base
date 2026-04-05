#include <stdio.h>
#include <string.h>

// В файле input.txt записаны символы. Необходимо разработать функцию, которая меняет местами пары соседних символов не обращая внимание на символы пробел. Если количество символов нечетно (пробелы не считаем), то последний символ не меняем. Результат записать в файл output.txt.

#define MAX_LENGTH 5000

// Функция для обмена соседних символов, игнорируя пробелы
void swap_adjacent_ignore_spaces(char *str)
{
    char temp_chars[MAX_LENGTH];  // Временный массив для хранения непробельных символов
    int temp_count = 0;         // Количество непробельных символов
    int i, j;

    // Извлекаем все непробельные символы в отдельный массив
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            temp_chars[temp_count++] = str[i];
        }
    }

    // Меняем местами пары соседних символов в массиве непробельных
    for (j = 0; j < temp_count - 1; j += 2) {
        char temp = temp_chars[j];
        temp_chars[j] = temp_chars[j + 1];
        temp_chars[j + 1] = temp;
    }

    // Возвращаем символы обратно в исходную строку, сохраняя пробелы на своих местах
    j = 0;  // Индекс для массива temp_chars
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            str[i] = temp_chars[j++];
        }
    }
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

    // Применяем функцию обмена символов
    swap_adjacent_ignore_spaces(sentence);


    // Записываем результат в output.txt
    fprintf(outputfile, "%s\n", sentence);

    // Закрываем файлы
    fclose (inputfile);
    fclose (outputfile);

    return 0;
}


