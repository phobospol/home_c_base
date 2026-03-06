#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
// Считать массив из 10 элементов и отобрать в другой массив все числа, у которых вторая с конца цифра (число десятков) – ноль.

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

int Sort_second_end_zero(int a[], int result[], int size)
{
    int k = 0;
    for(int i = 0; i < size; i++)
    {
        if(abs(a[i] / 10) % 10 == 0)
        {
            result[k] = a[i];
            k++;
        }
    }
    return k;
}

int main()

{
    int arr[SIZE]= {0};
    int result[SIZE]={0};;
    Input(arr,SIZE);
    Print(result, Sort_second_end_zero(arr, result, SIZE));
    return 0;
}
