#include <stdio.h>
#include <inttypes.h>
//Считать массив из 10 элементов и посчитать сумму положительных элементов массива.
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

int PosNumber(int *arr,int len)
{
    int SumPosNumber=0,i;
    for (i = 0; i < len; i++)
        if (arr[i]>0)
        {
            SumPosNumber += arr[i];
        }
    return SumPosNumber;
}

int main(int argc, char **argv)
{
    int arr[SIZE]= {0};
    Input(arr,SIZE);
    printf("%d", PosNumber(arr,SIZE));
    return 0;
}


