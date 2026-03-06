#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
//Считать массив из 10 элементов и выполнить циклический сдвиг ВПРАВО на 1.

#define SIZE 10

int Input(int* arr, int n)
{
    int i;
    for(i=0; i<n; i++)
        scanf("%d",&arr[i]);
    return i;
}

void Print(int *arr,int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

// циклический сдвиг массива вправо на 1 элемент
void shift_array_right(int size, int a[])
{
    int tmp = a[size-1];
    for (size_t i = size-1; i>0; i-- )
    {
        a[i] = a[i-1];
    }
    a[0] = tmp;
}

int main()

{
    int arr[SIZE]= {0};
    Input(arr,SIZE);
    shift_array_right(SIZE, arr);
    Print(arr,SIZE);
    return 0;
}
