#include <stdio.h>

// В файле input.txt дана строка слов, разделенных пробелами. Найти самое длинное слово и вывести его в файл output.txt. Случай, когда самых длинных слов может быть несколько, не обрабатывать.

int main()
{
    FILE *infile, *outfile;
    char str[1001];
    char maxWord[1001] = {0}; // самое длинное слово
    char current[1001];       // текущее слово

    int i = 0, j = 0;
    int maxLen = 0;

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

    while (str[i] != '\0')
    {
        if (str[i] != ' ' && str[i] != '\n')
        {
            current[j++] = str[i]; // собираем слово
        } else {
            current[j] = '\0'; // конец слова

            if (j > maxLen) {
                maxLen = j;
                for (int k = 0; k <= j; k++)
                {
                    maxWord[k] = current[k];
                }
            }

            j = 0; // начинаем новое слово
        }
        i++;
    }

    // Открываем output.txt для записи
    outfile = fopen("output.txt", "w");
    if (outfile == NULL) {
        perror("Could not open output.txt");
        return 1;
    }

    // проверка последнего слова (если строка не заканчивается пробелом)
    if (j > 0)
    {
        current[j] = '\0';
        if (j > maxLen)
        {
            for (int k = 0; k <= j; k++)
            {
                maxWord[k] = current[k];
            }
        }
    }

    fprintf(outfile, "%s", maxWord);
    fclose(outfile);

    return 0;
}
