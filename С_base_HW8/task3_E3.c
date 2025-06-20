#include <stdio.h>
#include <inttypes.h>
//Считать массив из 10 элементов и найти в нем максимальный и минимальный элементы и их номера.
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
int Min(int *arr,int len)
{
    int min=arr[0],i;
    for (i = 1; i < len; i++)
        if (min > arr[i])
        {
            min = arr[i];
        }
    return min;
}

int PosMin(int *arr,int len)
{
    int min=arr[0],i,pos_m=1;
    for (i = 1; i < len; i++)
        if (min > arr[i])
        {
            min = arr[i];
            pos_m = i+1;
        }
    return pos_m;
}

int Max(int *arr,int len)
{
    int max=arr[0],i;
    for (i = 1; i < len; i++)
        if (max < arr[i])
        {
            max = arr[i];
        }
    return max;
}

int PosMax(int *arr,int len)
{
    int max=arr[0],i,pos_M=1;
    for (i = 1; i < len; i++)
        if (max < arr[i])
        {
            max = arr[i];
            pos_M = i+1;
        }
    return pos_M;
}

int main(int argc, char **argv)
{
    int arr[SIZE]= {0};
    Input(arr,SIZE);
    printf("%d %d %d %d", PosMax(arr,SIZE), Max(arr,SIZE), PosMin(arr,SIZE), Min(arr,SIZE));
    return 0;
}
