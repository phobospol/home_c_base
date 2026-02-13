#include <stdio.h>
//Ввести натуральное число и определить, верно ли, что сумма его цифр равна 10.
int main()
{
    int n;
    scanf("%d", &n);

    int sum = 0;
//С помощью цикла while считаем сумму его цифр числа n
    while (n > 0) 
    {
        sum += n % 10;
        n /= 10;
    }

    if (sum == 10)
        printf("YES");
    else
        printf("NO");

    return 0;
}
