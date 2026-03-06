#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
// Считать 10 чисел в диапазоне от -500 до 500 и разложить по двум массивам: в одни помещать только положительные, во второй - только отрицательные. Числа, равные нулю, игнорировать. Вывести на экран все элементы обоих массивов.
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
    // printf("\n");
}

void Sort_pos_neg_digit(int a[], int size)
{
    int pos[SIZE];
    int neg[SIZE];
    int p = 0, n = 0;
    for(int i = 0; i < SIZE; i++)
    {
        if(a[i] > 0)
        {
            pos[p] = a[i];
            p++;
        }
        else if(a[i] < 0)
        {
            neg[n] = a[i];
            n++;
        }
    }
    Print(pos, p);
    Print(neg, n);
}

int main()

{
    int arr[SIZE]= {0};
    Input(arr,SIZE);
    Sort_pos_neg_digit(arr, SIZE);
    return 0;
}

