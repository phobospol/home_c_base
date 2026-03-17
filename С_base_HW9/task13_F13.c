/*
#include <stdio.h>

//Составить функцию которая возвращает количество элементов на заданном отрезке [from, to] для массива.Прототип функции int count_between(int from, int to, int size, int a[])

void Input(int n, int a[])
{
    for(int i=0; i< n; i++)
        scanf("%d",&a[i]);
}
*/

// Функция count_between возвращает количество элементов в массиве a[size], которые находятся в диапазоне [from, to]
int count_between (int from, int to, int size, int a[])
{
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        if(a[i] >= from && a[i] <= to) //проверяет, лежит ли элемент в интервале [from, to]
            count++; //Если элемент подходит, увеличиваем count
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
    enum {BUFFER_SIZE = 12};
    int input[BUFFER_SIZE]; // входной массив
    int from = 2, to = 4;
    Input(BUFFER_SIZE,input);
    printf("%d\n", count_between(from, to, BUFFER_SIZE, input));

    return 0;
}
*/
