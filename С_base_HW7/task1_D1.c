#include <stdio.h>
//Составить рекурсивную функцию, печать всех чисел от 1 до N
void rec (int n) { //рекурсивная функция
    if (n>1) //условие функции
        rec (n-1); //шаг функции
    printf ("%5d", n);
}
int main (void) {
    int a;
    scanf ("%d", &a);
    rec (a);
    return 0;
}
