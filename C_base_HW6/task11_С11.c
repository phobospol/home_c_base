#include <stdio.h>
// Составить функцию, которая определяет наибольший общий делитель двух натуральных и привести пример ее использования. int nod(int a, int b)
int nod (int a, int b)
{
    for (; b != 0 ;)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n",nod ( a, b));
    return 0;
}

