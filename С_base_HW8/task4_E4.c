#include <stdio.h>
#include <inttypes.h>
//Считать массив из 10 элементов и найти в нем два максимальных элемента и напечатать их сумму.
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

int Sum_Max(int *arr,int len)
{
    // scanf("%d", &arr[0]);
    int i, max1, max2;
    max1=0;
    max2=1;
    for (i = 1; i < len; i++)
    {
        if (arr[i]>arr[max1])
        {
            max2=max1;
            max1=i;
        }
        else if (arr[i]>arr[max2])
            max2=i;
    }
    return (arr[max1]+arr[max2]);
}

int main(int argc, char **argv)
{
    int arr[SIZE]= {0};
    Input(arr,SIZE);
    printf("%d", Sum_Max(arr,SIZE));
    return 0;
}

