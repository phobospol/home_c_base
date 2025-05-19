#include <stdio.h>
//Составить функцию, возведение числа N в степень P. int power(n, p) и привести пример ее использования.
int power (int n, int p)
{
    int results = 1;
    for (int i=1; i <= p; i++) {
        results = results * n;
    }
    return results;
}
int main()//использование функции power в main
{
    int n, p;
    scanf("%d %d", &n, &p);
    printf ("%d\n", power (n, p));
    return 0;
}


