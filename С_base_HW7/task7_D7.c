#include <stdio.h>
//Составить рекурсивную функцию, печать всех чисел от N до 1.
void rec (int n) { //рекурсивная функция
    printf ("%d ", n);//вывод на печать всех чисел от N до 1.
    if (n>1) //условие функции
        rec (n-1); //шаг функции
}
int main (void) {
    int a;
    scanf ("%d", &a);
    rec (a);
    return 0;
}
