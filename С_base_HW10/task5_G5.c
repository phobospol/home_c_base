#include <stdio.h>
#include <string.h>

//В файле input.txt дана символьная строка не более 1000 символов. Необходимо заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и строчные. Результат записать в output.txt.

int main() 
{
    FILE *infile, *outfile;
    char str[1001]; // до 1000 символов + '\0'

    // Открытие input.txt
    infile = fopen("input.txt", "r");
    if (infile == NULL)
    {
        printf("Could not open input.txt");
        return 1;
    }

    // Считываем строку (всю строку, включая пробелы и знаки)
    if (fgets(str, sizeof(str), infile) == NULL)
    {
        printf("Line reading error");
        fclose(infile);
        return 1;
    }
    fclose(infile);

    // Замена 'a' <-> 'b' и 'A' <-> 'B'
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'a')
        {
            str[i] = 'b';
        } else if (str[i] == 'b') {
            str[i] = 'a';
        } else if (str[i] == 'A') {
            str[i] = 'B';
        } else if (str[i] == 'B') {
            str[i] = 'A';
        }
    }

    // Запись в output.txt
    outfile = fopen("output.txt", "w");
    if (outfile == NULL)
    {
        perror("Could not open output.txt");
        return 1;
    }

    fputs(str, outfile);
    fclose(outfile);

    return 0;
}

