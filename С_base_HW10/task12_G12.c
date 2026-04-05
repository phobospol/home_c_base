#include <stdio.h>

// В файле input.txt дано предложение требуется разобрать его на отдельные слова. Напечатать каждое слово на отдельной строке в файл output.txt.

int main()
{

    FILE *infile, *outfile;
    
    // Открываем input.txt для чтения
    infile = fopen("input.txt", "r");
    if (infile == NULL) {
        perror("Could not open input.txt");
        return 1;
    }
    
    // Открываем output.txt для записи
    outfile = fopen("output.txt", "w");
    if (outfile == NULL)
    {
        perror("Could not open output.txt");
        return 1;
    }

    char str[1001];
    
    // Считываем строку из файла
    if (fgets(str, sizeof(str), infile) == NULL)
    {
        perror("Error reading from input.txt");
        fclose(infile);
        fclose(outfile);
        return 1;
    }
    fclose(infile);

    int i = 0;
    while (str[i] != '\0' && str[i] != '\n') 
    {
        // пропускаем пробелы
        while (str[i] == ' ' && str[i] != '\0' && str[i] != '\n') 
        {
            i++;
        }

        if (str[i] == '\0' || str[i] == '\n') break;

        // печатаем слово
        while (str[i] != ' ' && str[i] != '\0' && str[i] != '\n') 
        {
            fputc(str[i], outfile);
            i++;
        }

        // переход на новую строку после слова
        fputc('\n', outfile);
    }

    fclose(outfile);
    return 0;
}
