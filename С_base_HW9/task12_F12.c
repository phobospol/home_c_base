/*
#include <stdio.h>

//Составить функцию которая меняет в массиве минимальный и максимальный элемент местами.Прототип функции void change_max_min(int size, int a[])

void Input(int n, int a[])
{
    for(int i=0; i< n; i++)
        scanf("%d",&a[i]);
}
*/

// Функция change_max_min меняет местами минимальный и максимальный элементы массива
void change_max_min(int size, int a[])
{
    int min_i = 0;
    int max_i = 0;
    
// Находим индексы минимального и максимального элементов
    for(int i = 1; i < size; i++)
    {
        if(a[i] < a[min_i])
            min_i = i;

        if(a[i] > a[max_i])
            max_i = i;
    }
    
// Меняем местами
    int temp = a[min_i];
    a[min_i] = a[max_i];
    a[max_i] = temp;
}
/*
void Print(int n, int a[])
{
    for (int i = 0; i < n; i++)
        printf("%d ",a[i]);
    printf("\n");
}

int main()
{
    enum {BUFFER_SIZE =10};
    int input[BUFFER_SIZE]; // входной массив
    Input(BUFFER_SIZE,input);
    change_max_min(BUFFER_SIZE, input);
    Print (BUFFER_SIZE,input);

    return 0;
}
*/
