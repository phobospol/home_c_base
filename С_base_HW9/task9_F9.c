/*
#include <stdio.h>

// Составить только функцию которая в массиве находит максимальный из отрицательных элементов и меняет его местами с последним элементом массива. Гарантируется, что в массиве только один такой элемент или же такой элемент отсутствует. Если отрицательных элементов нет - массив не менять.

void Input(int n, int a[])
{
    for(int i=0; i< n; i++)
        scanf("%d",&a[i]);
}
*/

void swap_negmax_last(int size, int a[])
{
    int index = -1;

    // поиск максимального отрицательного элемента
    for(int i = 0; i < size; i++)
    {
        if(a[i] < 0)
        {
            if(index == -1 || a[i] > a[index])
                index = i;
        }
    }

    // если отрицательный элемент найден — меняем местами
    if(index != -1)
    {
        int temp = a[index];
        a[index] = a[size - 1];
        a[size - 1] = temp;
    }
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
    swap_negmax_last(BUFFER_SIZE, input);
    Print(BUFFER_SIZE,input);

    return 0;
}
*/

