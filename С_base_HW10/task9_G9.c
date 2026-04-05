#include <stdio.h>

// В файле input.txt строка из меленьких и больших английских букв, знаков препинания и пробелов. Требуется удалить из нее повторяющиеся символы и все пробелы. Результат записать в файл output.txt.

int main()
{

    FILE *infile, *outfile;
    char str[1001];
    int used[256] = {0}; // массив для отметки символов

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
    if (outfile == NULL) {
        perror("Could not open output.txt");
        return 1;
    }

    int i = 0;
    while (str[i] != '\0')
    {
        char c = str[i];

        // пропускаем пробелы и перенос строки
        if (c != ' ' && c != '\n')
        {
            // если символ еще не встречался
            if (used[(unsigned char)c] == 0)
            {
                fputc(c, outfile);          // записываем
                used[(unsigned char)c] = 1; // отмечаем
            }
        }

        i++;
    }

    fclose(outfile);

    return 0;
}
