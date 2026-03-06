#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
//Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4.

#define SIZE 12

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

// циклический сдвиг массива вправо на 4 элемента
void shift_array_right_four(int size, int a[])
{
    int temp[size];
    for (size_t i = 0; i < size; i++ )
    {
        temp[(i + 4) % size] = a[i];
    }
    for (size_t i = 0; i < size; i++)
    {
        a[i] = temp[i];
    }
}

int main()

{
    int arr[SIZE]= {0};
    Input(arr,SIZE);
    shift_array_right_four(SIZE, arr);
    Print(arr,SIZE);
    return 0;
}
