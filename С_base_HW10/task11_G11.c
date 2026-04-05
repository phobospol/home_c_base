#include <stdio.h>

// В файле input.txt дано предложение. Необходимо определить, сколько слов заканчиваются на букву 'а'. Ответ записать в файл output.txt.

int main()
{

    FILE *infile, *outfile;

    char str[1001];
    int count = 0;
    int i = 0;

    // Открываем input.txt для чтения
    infile = fopen("input.txt", "r");
    if (infile == NULL) {
        perror("Could not open input.txt");
        return 1;
    }

    // Считываем строку из файла
    if (fgets(str, sizeof(str), infile) == NULL)
    {
        perror("Error reading from input.txt");
        fclose(infile);
        return 1;
    }
    fclose(infile);

    // Открываем output.txt для записи
    outfile = fopen("output.txt", "w");
    if (outfile == NULL)
    {
        perror("Could not open output.txt");
        return 1;
    }

    while (str[i] != '\0' && str[i] != '\n')
    {
        // пропускаем пробелы
        while (str[i] == ' ' && str[i] != '\0' && str[i] != '\n')
        {
            i++;
        }

        if (str[i] == '\0' || str[i] == '\n') break;

        char last = 0; // инициализация
        // собираем слово
        while (str[i] != ' ' && str[i] != '\0' && str[i] != '\n')
        {
            last = str[i];
            i++;
        }

        if (last == 'a')
        {
            count++;
        }
    }

    fprintf(outfile, "%d", count);

    fclose(outfile);

    return 0;
}

