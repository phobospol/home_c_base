/*
#include <stdio.h>
#include <math.h>
*/
/* Cia очень любит равносторонние треугольники. Он все время выкладывает их из камней. Ling дал Cia камни и попросил его составить такой треугольник если это возможно. Помогите Cia сложить треугольник используя все камни или напечатайте слов NO, если это невозможно. Пример треугольников, которые составляет Cia:

 *
* *

  *
 * *
* * *

   *
  * *
 * * *
* * * *
Во входном файле input.txt записано некоторое количество символов * (камней). Необходимо построить равносторонний треугольник используя все символы * и символ пробел, записать ответ в выходной файл output.txt. Между соседними символами * строго один пробел. Если треугольник невозможно составить, используя все камни, то необходимо записать единственное слово NO в файл output.txt.
*/

/*
#define MAX_LENGTH 10000

int main(int argc, char **argv)
{
    FILE *inputfile, *outputfile;
    int star_count = 0;

    // Открываем input.txt
    inputfile = fopen("input.txt", "r");
    if (inputfile == NULL)
    {
        perror("Could not open input.txt");
        return 1;
    }

    // Открываем output.txt
    outputfile = fopen("output.txt", "w");
    if (outputfile == NULL)
    {
        perror("Could not open output.txt");
        fclose(inputfile);
        return 1;
    }

    // Считаем количество '*'
    int c;
    while ((c = fgetc(inputfile)) != EOF)
    {
        if (c == '*')
        {
            star_count++;
        }
    }
    fclose(inputfile);

    // Если нет ни одного камня — треугольник невозможен
    if (star_count == 0)
    {
        fprintf(outputfile, "NO");
        fclose(outputfile);
        return 0;
    }

    // Проверяем формулу: h(h+1)/2 = star_count
    int discriminant = 1 + 8 * star_count;
    int sqrt_disc = (int)sqrt(discriminant);

    // Проверка на полный квадрат
    if (sqrt_disc * sqrt_disc != discriminant)
    {
        fprintf(outputfile, "NO");
        fclose(outputfile);
        return 0;
    }

    int h = (-1 + sqrt_disc) / 2;

    // Дополнительная защита от ошибок округления
    if (h * (h + 1) / 2 != star_count || h <= 0)
    {
        fprintf(outputfile, "NO");
        fclose(outputfile);
        return 0;
    }

    // Строим треугольник
    for (int row = 1; row <= h; row++)
    {
        // Отступы
        for (int space = 0; space < h - row; space++)
        {
            fprintf(outputfile, " ");
        }

        // Звёздочки
        for (int stone = 1; stone <= row; stone++)
        {
            fprintf(outputfile, "*");
            if (stone < row)
            {
                fprintf(outputfile, " ");
            }
        }

        // Переход строки (кроме последней можно, но не обязательно)
        if (row < h)
        {
            fprintf(outputfile, "\n");
        }
    }

    fclose(outputfile);
    return 0;
}
*/

#include <stdio.h>

/* Cia очень любит равносторонние треугольники. Он все время выкладывает их из камней. Ling дал Cia камни и попросил его составить такой треугольник если это возможно. Помогите Cia сложить треугольник используя все камни или напечатайте слов NO, если это невозможно. Пример треугольников, которые составляет Cia:

 *
* *

  *
 * *
* * *

   *
  * *
 * * *
* * * *
Во входном файле input.txt записано некоторое количество символов * (камней). Необходимо построить равносторонний треугольник используя все символы * и символ пробел, записать ответ в выходной файл output.txt. Между соседними символами * строго один пробел. Если треугольник невозможно составить, используя все камни, то необходимо записать единственное слово NO в файл output.txt.
*/

int main(int argc, char **argv)
{
    FILE *inputfile, *outputfile;
    int star_count = 0;

    // Открываем input.txt
    inputfile = fopen("input.txt", "r");
    if (inputfile == NULL)
    {
        perror("Could not open input.txt");
        return 1;
    }

    // Открываем output.txt
    outputfile = fopen("output.txt", "w");
    if (outputfile == NULL)
    {
        perror("Could not open output.txt");
        fclose(inputfile);
        return 1;
    }

    // Считаем количество '*'
    int c;
    while ((c = fgetc(inputfile)) != EOF)
    {
        if (c == '*')
        {
            star_count++;
        }
    }
    fclose(inputfile);

    // Если нет звёзд — сразу NO
    if (star_count == 0)
    {
        fprintf(outputfile, "NO");
        fclose(outputfile);
        return 0;
    }

    // Ищем высоту через сумму 1 + 2 + ... + h
    int h = 0;
    int sum = 0;

    while (sum < star_count)
    {
        h++;
        sum += h;
    }

    // Если не совпало — нельзя построить
    if (sum != star_count)
    {
        fprintf(outputfile, "NO");
        fclose(outputfile);
        return 0;
    }

    // Строим треугольник
    for (int row = 1; row <= h; row++)
    {
        // Отступы
        for (int space = 0; space < h - row; space++)
        {
            fprintf(outputfile, " ");
        }

        // Звёзды с одним пробелом между ними
        for (int stone = 1; stone <= row; stone++)
        {
            fprintf(outputfile, "*");
            if (stone < row)
            {
                fprintf(outputfile, " ");
            }
        }

        // Перевод строки (не добавляем после последней строки)
        if (row < h)
        {
            fprintf(outputfile, "\n");
        }
    }

    fclose(outputfile);
    return 0;
}

