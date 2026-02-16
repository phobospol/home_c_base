#include <stdio.h>
//Составить функцию, которая переводит число N из десятичной системы счисления в p-ичную систему счисления. Два целых числа. n ≥ 0 и 2 ≤ p ≤ 9
/*
int converter (int n, int p)
{
    if (n == 0)
        return 0;

    int remainder;
    int exponent = 1;
    int res = 0;
// собираем новое число справа налево, умножая разряд на 10.
    while (n > 0) 
    {
        remainder = n % p;
        res += remainder * exponent;
        exponent *= 10;
        n /= p;
    }

    return res;
}
*/
int converter (int n, int p)
{
    if (n == 0)
        return 0;
        
    int power = 1;
    int res = 0;

    // находим наибольшую степень p, не превышающую n
    while (power <= n / p)
    {
        power *= p;
    }
    
    // Сначала находим самую большую степень p, которая ≤ n. Потом извлекаем цифры слева направо 
    while (power > 0)
    {
        res = res * 10 + n / power;
        n = n % power;
        power /= p;
    }
    
    return res;
}


int main(int argc, char **argv)
{
    int n, p;
    scanf ("%d %d", &n, &p);
    printf ("%d\n", converter(n,p));
    return 0;
}

