#include <stdio.h>
//Составить функцию, которая вычисляет косинус как сумму ряда (с точностью 0.001) cos(x) = 1 - x2/2! + x4/4! - x6/6! + ... (x в радианах)
float cosinus(float x)
{
    float rad = x * 3.1415926f / 180.0f;  // перевод в радианы
    float sum = 0.0f;
    float term;
    int sign = 1;   // знак (+ / -)

    for (int i = 0; ; i += 2)
    {
        // вычисляем x^i
        float power = 1.0f;
        for (int j = 0; j < i; j++)
            power *= rad;

        // вычисляем i!
        float fact = 1.0f;
        for (int j = 1; j <= i; j++)
            fact *= j;

        term = sign * power / fact;

        if (term < 0.001f && term > -0.001f)
            break;

        sum += term;
        sign = -sign;  // меняем знак
    }

    return sum;
}

int main()
{
    float x;
    scanf("%f", &x);

    printf("%.3f\n", cosinus(x));

    return 0;
}
