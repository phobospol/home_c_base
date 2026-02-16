#include <stdio.h>
//Составить функцию float sinus(float x), которая вычисляет синус как сумму ряда (с точностью 0.001) sin(x) = x - x3/3! + x5/5! - x7/7! + ...(x в радианах)

float sinus(float x)
{
    float rad = x * 3.1415926f / 180.0f; // перевод в радианы
    float term = rad;    // первый член ряда
    float sum = 0.0f;
    int n = 1;

    for (;term > 0.001f || term < -0.001f;)// в цикле for проверяем term пока их модуль больше 0.001 
    {
        sum += term;//Мы прибавляем члены ряда, пока их модуль больше 0.001
        term *= -rad * rad / ((2*n) * (2*n + 1));//Каждый следующий член ряда получается из предыдущего:
        n++;
    }

    return sum;
}

int main()
{
    float x;
    scanf("%f", &x);

    printf("%.3f\n", sinus(x));

    return 0;
}
