#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

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

void swap(int*a,int*b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//Реверс массива
void revers_array(int a[], int size)
{
    for(size_t i=0; i<size/2-2; i++)
    {
        swap(&a[i], &a[size-6-i]);
    }
    for(size_t i=5; i<size-2; i++)
    {
        swap(&a[i], &a[size+4-i]);
    }
    return;
}

int main(void)
{
    //int arr[SIZE];
    int arr[SIZE]= {0};
    Input(arr,SIZE);
    revers_array(arr,SIZE);
    Print(arr,SIZE);
    return 0;
}
