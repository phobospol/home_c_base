#include <stdio.h>
//Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования.
int sumnaturalnumber (int n) {
    //тело функции
    int i, s=0;
    for (i=0; i<=n; i++)
        s+=i;
    return (s);
}
int main()//использование функции sumnaturalnumber в main
{
    int n;
    scanf("%d",&n);
    printf ("%d ", sumnaturalnumber (n));
    return 0;
}
