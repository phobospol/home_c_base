//*
#include <stdio.h>

//Дан целочисленный массив из 30 элементов. Элементы массива могут принимать произвольные целые значения помещающиеся в int. Необходимо создать функцию, которая находит и выводит в порядке возрастания номера двух элементов массива, сумма которых минимальна.

void Input(int n, int a[])
{
    for(int i=0; i< n; i++)
        scanf("%d",&a[i]);
}
//*/

// find_min_pair находит два элемента с минимальной суммой. Выводит номера этих элементов (индексы) в порядке возрастания.
void find_min_pair (int size, int a[])
{
    int min_sum = a[0] + a[1];
    int i_min = 0, j_min = 1;

    for(int i = 0; i < size - 1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            int sum = a[i] + a[j];

            if(sum < min_sum)
            {
                min_sum = sum;
                i_min = i;
                j_min = j;
            }
        }
    }

    printf("%d %d", i_min, j_min);
}

//*
void Print(int n, int a[])
{
    for (int i = 0; i < n; i++)
        printf("%d ",a[i]);
    printf("\n");
}

int main()
{
    enum {BUFFER_SIZE =30};
    int input[BUFFER_SIZE]; // входной массив
    Input(BUFFER_SIZE,input);
    find_min_pair(BUFFER_SIZE, input);

    return 0;
}
//*/

