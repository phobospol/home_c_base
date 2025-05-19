#include <stdio.h>
/*Описать функцию вычисления f(x) по формуле: 
f(x)= x*x при -2 ≤ x < 2;
x*x+4x+5 при x ≥ 2;
4 при x < -2.
Используя эту функцию для n заданных чисел, вычислить f(x). Среди вычисленных значений найти наибольшее.*/
int function (int x)
{
    int xa=0;
    int xb=0;
    int xc=0;
    if ((-2)<=x && x<2) {
        xa=(x*x);
    }
    if (x>=2) {
        xb=(x*x+4*x+5);
    }
    if (x<-2) {
        xc=4;
    }
    return (xa+xb+xc);
}
int main()//использование функции function в main
{
    int x;
    int max=0;
    while (1) {
        scanf("%d", &x);
        if (x==0) {
            break;
        }
        while (function (x)>max)
            max=function (x);
    }
    printf ("%d ", max);
    return 0;
}

