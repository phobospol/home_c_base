#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
//Считать массив из 10 элементов и отсортировать его по последней цифре.

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

// сортировка пузырьком по последней цифре 
void BubbleSortlastdigit (int size, int a[])
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (abs(a[j] % 10) > abs(a[j + 1] % 10))
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()

{
    int arr[SIZE]= {0};
    Input(arr,SIZE);
    BubbleSortlastdigit (SIZE, arr);
    Print(arr,SIZE);
    return 0;
}
