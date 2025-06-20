#include <stdio.h>
//Составить рекурсивную функцию, которая определяет сумму всех чисел от 1 до N
int recSum (int n) { //рекурсивная функция
    if (n<=1) //базовое условие функции
        return n;
    return n+recSum (n-1); //рекурсивный шаг функции
}
int main () {
    int a;
    scanf ("%d", &a);
    printf ("%d", recSum (a));
    return 0;
}

