//*
#include <stdio.h>
#include <stdlib.h>

//Дан целочисленный массив из 10 элементов. Необходимо определить количество четных и нечетных чисел. Если количество чётных чисел больше, чем количество нечётных, заменить каждое нечетное число на произведение нечетных цифр в его десятичной записи. Если количество нечётных чисел больше или равно количеству чётных, заменить каждое чётное число на произведение чётных цифр в его десятичной записи.

void Input(int SIZE, int a[]) // ввод матрицы
{
    for(int i=0; i< SIZE; i++)
        scanf("%d",&a[i]);
}

// Функция для вычисления произведения нечётных цифр числа
int product_odd_digits(int x)
{
    int p = 1;
    int found = 0;
    x = abs(x);

    while (x > 0)
    {
        int d = x % 10;
        if (d % 2 == 1)
        {
            p *= d;
            found = 1;
        }
        x /= 10;
    }

    if (!found) return 0; // если нечётных цифр нет, возвращаем 0
    return p;
}

// Функция для вычисления произведения чётных цифр числа
int product_even_digits(int x)
{
    int p = 1;
    int found = 0;
    x = abs(x);

    while (x > 0)
    {
        int d = x % 10;
        if (d % 2 == 0)
        {
            p *= d;
            found = 1;
        }
        x /= 10;
    }

    if (!found) return 0; // если чётных цифр нет, возвращаем 0
    return p;
}


void Print(int n, int a[])
{
    for (int i = 0; i < n; i++)
        printf("%d ",a[i]);
    printf("\n");
}


int main()
{
    enum {BUFFER_SIZE = 10};
    int input [BUFFER_SIZE]; // входной массив
    int even = 0, odd = 0;
    Input(BUFFER_SIZE,input);

    // Считаем количество четных и нечетных чисел
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        if (input[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    // Если четных больше, заменяем все нечетные числа на произведение их нечётных цифр
    if (even > odd)
    {
        for (int i = 0; i < BUFFER_SIZE; i++)
        {
            if (input[i] % 2 != 0)
                input[i] = product_odd_digits(input[i]);
        }
    }

    // Если нечетных больше или равно, заменяем все четные числа на произведение их чётных цифр
    else
    {
        for (int i = 0; i < BUFFER_SIZE; i++)
        {
            if (input[i] % 2 == 0)
                input[i] = product_even_digits(input[i]);
        }
    }
    Print(BUFFER_SIZE, input);

    return 0;

}



