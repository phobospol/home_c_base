#include <stdio.h>
//Составить логическую функцию, которая определяет, верно ли, что в заданном числе сумма цифр равна произведению. int is_happy_number(int n)
int is_happy_number(int n);

int main()
{
    int n;
    scanf("%d", &n);
    printf ("%s", is_happy_number(n)? "YES\n":"NO\n");

    return 0;
}

int is_happy_number(int n)
{
    int sum = 0;
    int product = 1;

    if (n == 0)// Специальный случай для числа 0, если n=0 то вернуть 0
        return 0;

    while (n > 0)//в цикле проверяем сумму и произведение всех цифр в числе пока n>0
    {
        int digit = n % 10;
        sum += digit;
        product *= digit;
        n /= 10;
    }

    return sum == product;//если сумма и произведение равны то вернуть 1
}

