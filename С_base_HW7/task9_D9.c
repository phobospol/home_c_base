#include <stdio.h>
//Дано натуральное число N. Вычислите сумму его цифр. Необходимо составить рекурсивную функцию int sum_digits(int n)
int sum_digits(int n)
{
    if (n < 10)// если остаётся одна цифра — рекурсия прекращается
        return n;

    return n % 10 + sum_digits(n / 10);//взять последнюю цифру и прибавить сумму цифр оставшейся части
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("%d\n", sum_digits(n));

    return 0;
}
