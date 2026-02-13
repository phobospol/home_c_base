#include <stdio.h>
// Вывести на экран ряд чисел Фибоначчи, состоящий из n элементов.
int main( void )
{
    long long n, i, f1, f2, m;
    scanf("%lld", &n);
    f1 = 1;
    f2 = 1;
/*    if (n == 1)
        printf("1");
    else if (n != 0)
    {
        printf("1 1 ");
        for (i = 2; i < n; ++i)
        {
            m = f1 + f2;
            f1 = f2;
            f2 = m;
            printf("%u ", f2);
        }
    }
    */
    if (n <= 0)
        return 0;
        
    if (n >= 1)
        printf("%lld ", f1);
        
    if (n >= 2)
        printf("%lld ", f2);
//В цикле for производим расчет ряда чисел Фибоначчи состоящий из n элементов
    for ( i = 3; i <= n; i++) 
    {
        m = f1 + f2;
        printf("%lld ", m);
        f1 = f2;
        f2 = m;
    }
    return 0;
}
