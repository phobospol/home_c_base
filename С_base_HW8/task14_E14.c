#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
// Считать массив из 10 элементов и выделить в другой массив все числа, которые встречаются более одного раза. В результирующем массиве эти числа не должны повторяться.

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

int FindDuplicates(int a[], int res[], int size)
{
    int k = 0;

    for(int i = 0; i < size; i++)
    {
        int count = 0;

        // считаем сколько раз встречается число
        for(int j = 0; j < size; j++)
        {
            if(a[i] == a[j])
                count++;
        }

        // если больше одного раза
        if(count > 1)
        {
            int exist = 0;

            // проверяем есть ли уже в результирующем массиве
            for(int m = 0; m < k; m++)
            {
                if(res[m] == a[i])
                {
                    exist = 1;
                    break;
                }
            }

            if(exist == 0)
            {
                res[k] = a[i];
                k++;
            }
        }
    }

    return k;
}

int main()

{
    int arr[SIZE]= {0};
    int res[SIZE]= {0};;
    Input(arr,SIZE);
    Print(res, FindDuplicates(arr, res, SIZE));
    return 0;
}

