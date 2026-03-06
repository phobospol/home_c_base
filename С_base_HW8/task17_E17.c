#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
//Дан массив из 10 элементов. В массиве найти элементы, которые в нем встречаются только один раз, и вывести их на экран.

#define SIZE 10

int Input(int* arr, int n)
{
    int i;
    for(i=0; i<n; i++)
        scanf("%d",&arr[i]);
    return i;
}

void PrintUnique(int a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        int count = 0;
        for(int j = 0; j < size; j++)
        {
            if(a[i] == a[j])
                count++;
        }

        if(count == 1)
            printf("%d ", a[i]);
    }
}

int main()
{
    int arr[SIZE]= {0};
    Input(arr,SIZE);
    PrintUnique(arr, SIZE);
    return 0;
}
