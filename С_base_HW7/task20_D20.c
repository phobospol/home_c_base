#include <stdio.h>
//Написать рекурсивную функцию возведения целого числа n в степень p. int recurs_power(int n, int p) Используя данную функцию, решить задачу.

int recurs_power(int n, int p)
{
    if (p == 0) //Условие останова прямой рекурсии
        return 1;

    return n * recurs_power(n, p - 1); //Определение степени числа и рекурсивный вызов
}

int main()
{
    int n, p;
    scanf("%d %d", &n, &p);

    printf("%d\n", recurs_power(n, p));

    return 0;
}
