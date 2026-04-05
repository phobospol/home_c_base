#include <stdio.h>

//В файле input.txt дана строка, не более 1000 символов, содержащая буквы, целые числа и иные символы. Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив. Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0. Вывести массив по возрастанию в файл output.txt.

int main()
{
    FILE *infile, *outfile;
    char str[1001];
    int numbers[1000];
    int count = 0;

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

    int i = 0;
    while (str[i] != '\0')
    {
        // проверка: цифра ли это
        if (str[i] >= '0' && str[i] <= '9')
        {
            int num = 0;

            // собираем число
            while (str[i] >= '0' && str[i] <= '9')
            {
                num = num * 10 + (str[i] - '0');
                i++;
            }

            numbers[count++] = num;
        }

        else

        {
            i++;
        }
    }

    // сортировка (пузырьком)
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    // Открываем output.txt для записи
    outfile = fopen("output.txt", "w");
    if (outfile == NULL) {
        perror("Could not open output.txt");
        return 1;
    }

    // вывод
    for (int i = 0; i < count; i++)
    {
        fprintf(outfile, "%d", numbers[i]);
        if (i < count - 1)
        {
            fprintf(outfile, " ");
        }
    }

    fclose(outfile);

    return 0;
}
