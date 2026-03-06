#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
//Считать массив из 12 элементов и выполнить инверсию для каждой трети массива.
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
//Реверс части массива
void reverse_part(int *arr, int start, int end)
{
    while (start < end)
    {
        int tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;
        start++;
        end--;
    }
}

int main()

{
    int arr[SIZE]= {0};
    int part = SIZE / 3;
    Input(arr,SIZE);
    // реверс каждой трети массива
    reverse_part(arr, 0, part - 1);
    reverse_part(arr, part, 2 * part - 1);
    reverse_part(arr, 2 * part, SIZE - 1);
    Print(arr,SIZE);
    return 0;
}
