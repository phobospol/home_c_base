#include <stdio.h>

//В файле input.txt считать символьную строку, не более 10 000 символов. Посчитать количество строчных (маленьких) и прописных (больших) букв в введенной строке. Учитывать только английские буквы. Результат записать в файл output.txt.

int main()
{
    FILE *infile, *outfile;
    char ch;
    int lower_count = 0;
    int upper_count = 0;

    infile = fopen("input.txt", "r");
    if (infile == NULL)
    {
        printf("Could not open input.txt");
        return 1;
    }

    while ((ch = fgetc(infile)) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            lower_count++;
        } else if (ch >= 'A' && ch <= 'Z')
        {
            upper_count++;
        }
    }

    fclose(infile);

    outfile = fopen("output.txt", "w");
    if (outfile == NULL)
    {
        printf("Could not open output.txt");
        return 1;
    }

    fprintf(outfile, "%d %d\n", lower_count, upper_count);
    fclose(outfile);

    return 0;
}
