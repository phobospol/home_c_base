#include <stdio.h>
//Составить функцию логическую функцию, которая определяет, верно ли, что число простое. Используя функцию решить задачу. int is_prime(int n)

int is_prime(int n)
{
    if (n < 2)
        return 0;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}
int main()
{
    int n;
    scanf("%d", &n);

    if (is_prime(n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}




