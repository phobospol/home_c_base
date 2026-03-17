/*
#include <stdio.h>
#include <stdlib.h>

// Составить функцию которая определяет в массиве, состоящем из положительных и отрицательных чисел, сколько элементов превосходят по модулю максимальный элемент. Прототип функции int count_bigger_abs(int n, int a[])

void Input(int n, int a[])
{
    for(int i=0; i< n; i++)
        scanf("%d",&a[i]);
}
*/

int count_bigger_abs(int n, int a[])
{
    int max = a[0];

    // поиск максимального элемента
    for(int i = 1; i < n; i++)
    {
        if(a[i] > max)
            max = a[i];
    }

    int count = 0;

    // считаем элементы, у которых |a[i]| > max
    for(int i = 0; i < n; i++)
    {
        if(abs(a[i]) > max)
            count++;
    }

    return count;
}


/*
void Print(int n, int a[])
{
    for (int i = 0; i < n; i++)
        printf("%d ",a[i]);
    printf("\n");
}
*/

/*
int main()
{
    enum {BUFFER_SIZE = 10};
    int input[BUFFER_SIZE]; // входной массив
    Input(BUFFER_SIZE,input);
    printf("%d\n",count_bigger_abs (BUFFER_SIZE, input));

    return 0;
}
*/

