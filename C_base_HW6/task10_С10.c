#include <stdio.h>
// Составить функцию, печать всех простых множителей числа. Использовать ее для печати всех простых множителей числа. void print_simple(int n)

void print_simple(int n)
{
 
    for (int i = 2; i <= n; i++)
    {
        for (; n % i == 0;)
        {
            printf("%d ", i);
            n /= i;
        }
    }
}

int main()

{
    int n;
    scanf("%d", &n);
    print_simple(n);
    return 0;
}

