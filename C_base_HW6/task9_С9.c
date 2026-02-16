#include <stdio.h>
//Составить функцию вычисления N!. Использовать ее при вычислении факториала int factorial(int n) N Целое положительное число не больше 20
int factorial(int n) // Создаем функцию вычисления факториала
{
    int result = 1;

    for ( int i = 1; i <= n; i++) // Создаем цикл for в котором result умножаем на числа от 1 до n
    {
        result *= i;
    }

    return result;
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("%d\n", factorial(n));

    return 0;
}

