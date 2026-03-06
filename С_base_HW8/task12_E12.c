#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
//Считать массив из 10 элементов и отсортировать первую половину по возрастанию, а вторую – по убыванию.

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

// Отсортировать первую половину по возрастанию, а вторую – по убыванию.
void sort_half(int a[], int size)
{
    // первая половина (0..4) по возрастанию
    for(int i = 0; i < (size-1)/2; i++)
    {
        for(int j = 0; j < ((size-1)/2)- i; j++)
        {
            if(a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }

    // вторая половина (5..9) по убыванию
    for(int i = size/2; i < size-1; i++)
    {
        for(int j = size/2; j < (size-1) - (i - size/2); j++)
        {
            if(a[j] < a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}
int main()

{
    int arr[SIZE]= {0};
    Input(arr,SIZE);
    sort_half (arr, SIZE);
    Print(arr,SIZE);
    return 0;
}
