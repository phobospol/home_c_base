#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// В файле input.txt в одной строке фамилию, имя и отчество. Сформировать файл приветствие output.txt, где останутся имя и фамилия

int main(int argc, char **argv)
{
    FILE *inputfile, *outputfile;
    char fullname[MAX_LENGTH];
    char surname[MAX_LENGTH], name[MAX_LENGTH];

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
    if (fgets (fullname, MAX_LENGTH, inputfile) == NULL)
    {
        perror("File input.txt empty or a reading error occurred\n");
        fclose (inputfile);
        fclose (outputfile);
        return 1;
    }

    // Удаляем символ новой строки, если он есть
    size_t len = strlen (fullname);
    if (len > 0 && fullname [len-1] == '\n')
    {
        fullname[len-1] = '\0';
    }

    // Разбираем строку на части: фамилия, имя, отчество. Используя sscanf извлекаем первые два слова - фамилия и имя
    if (sscanf (fullname, "%s %s", surname, name) !=2)
    {
        perror("Incorrect data format in input.txt. Expected format: Last name, First name, Middle name \n");
        fclose (inputfile);
        fclose (outputfile);
        return 1;
    }

    // Записываем в output.txt приветствие запятую и Фамилию с именем
    fprintf(outputfile, "Hello, %s %s!\n", name, surname);

    // Закрываем файлы
    fclose (inputfile);
    fclose (outputfile);

    return 0;
}
