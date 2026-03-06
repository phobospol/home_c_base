#include <stdio.h>

//Переставить цифры в числе так, что бы получилось максимальное число.

#define SIZE 20

long long Input(void)

{
    long long i;
    scanf("%lld",&i);
    return i;
}

void Rearrange_numbers (int N, int a[])
{
    int count = 0;
    // если N==0 то печатаем 0
    if (N == 0)
    {
        printf("0");
    }

    // разбиваем число на цифры
    while (N > 0)
    {
        a[count++] = N % 10;
        N /= 10;
    }

    // сортировка цифр по убыванию (пузырьком)
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (a[j] < a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // вывод максимального числа
    for (int i = 0; i < count; i++)
    {
        printf("%d", a[i]);
    }
}

int main()
{
    int arr[SIZE]= {0};
    long long i = Input();
    Rearrange_numbers (i, arr);
    return 0;
}
