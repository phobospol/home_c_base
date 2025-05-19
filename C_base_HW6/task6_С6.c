#include <stdio.h>
//Необходимо составить функцию, которая определяет, сколько зерен попросил положить на N-ую клетку изобретатель шахмат (на 1-ую – 1 зерно, на 2-ую – 2 зерна, на 3-ю – 4 зерна, …)
unsigned long long geometricprogress (unsigned long long n) {
    //тело функции
    unsigned long long s=1;
    for (int i=2; i<=n; i++)
        s*=2;
    return (s);
}
int main()//использование функции geometricprogress в main
{
    int n;
    scanf("%d",&n);
    printf ("%llu", geometricprogress (n));
    return 0;
}
