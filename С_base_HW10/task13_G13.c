#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

//В файле input.txt записан полный адрес файла (возможно, без расширения). Необходимо изменить его расширение на ".html" и записать результат в файл output.txt.

int main(int argc, char **argv)
{
    FILE *inputfile, *outputfile;
    char path[MAX_LENGTH];
    char *dot_position;

    // Открываем файлы
    inputfile = fopen("input.txt", "r");
    if (inputfile == NULL)
    {
        perror("Could not open input.txt\n");
        return 1;
    }

    outputfile = fopen("output.txt", "w");
    if (outputfile == NULL)
    {
        perror("Could not open output.txt\n");
        fclose(inputfile);
        return 1;
    }

    // Читаем строку из input.txt
    if (fgets(path, MAX_LENGTH, inputfile) == NULL)
    {
        perror("File input.txt empty or a reading error occurred\n");
        fclose(inputfile);
        fclose(outputfile);
        return 1;
    }

    // Удаляем символ новой строки, если он есть
    size_t len = strlen(path);
    if (len > 0 && path[len-1] == '\n')
    {
        path[len-1] = '\0';
    }

    // Ищем последнюю точку в строке и сравниваем позиции . и / 
    char *slash_position = strrchr(path, '/');
    dot_position = strrchr(path, '.');
    if (dot_position != NULL && (slash_position == NULL || dot_position > slash_position))
    {
        // Если '.' есть и она стоит после '/', заменяем всё после неё на ".html"
        strcpy(dot_position, ".html");
    }
    else
    {
        // Если '.' нет или '/' стоит после нее, добавляем ".html" в конец строки
        strcat(path, ".html");
    }

    // Записываем результат в output.txt БЕЗ символа новой строки
    fprintf(outputfile, "%s", path);

    // Закрываем файлы
    fclose(inputfile);
    fclose(outputfile);

    return 0;
}
