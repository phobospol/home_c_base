#include <stdio.h>
//Дано натуральное число N. Посчитать количество «1» в двоичной записи числа.

int count_ones(int n)
{
    if (n == 0)
        return 0;

    return (n % 2) + count_ones(n / 2);//переводим в двоичное число (n%2) и с помощью рекурсивной функции удаляем последний бит  на обратном ходе рекурсии суммируем биты
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("%d\n", count_ones(n));

    return 0;
}
