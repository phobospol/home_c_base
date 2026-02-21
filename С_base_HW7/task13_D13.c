#include <stdio.h>
//Составить рекурсивную функцию, печать всех простых множителей числа.
void print_prime_factors(int n, int d)
{
    if (n == 1) //Останавливаем прямой ход рекурсии кода n==1
        return;

    if (n % d == 0) //Проверяем делится ли число на текущий делитель d Если делится печатаем d и вызываем функцию для n / d
    {
        printf("%d ", d);
        print_prime_factors(n / d, d);
    } 
    else
    {
        print_prime_factors(n, d + 1); //Если не делится увеличиваем d на 1
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    print_prime_factors(n, 2);

    return 0;
}
/*
if (d * d > n)
{
    printf("%d ", n);
    return;
}
*/
