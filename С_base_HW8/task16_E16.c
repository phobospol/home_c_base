#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
//Дан массив из 10 элементов. Определить, какое число в массиве встречается чаще всего. Гарантируется, что такое число ровно 1.
#define SIZE 10

int Input(int* arr, int n)
{
    int i;
    for(i=0; i<n; i++)
        scanf("%d",&arr[i]);
    return i;
}

/*void Print(int *arr,int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf("%d ",arr[i]);
    printf("\n");
}
*/

int Digit_most_frequentint (int a[], int size)
{
    int max_count = 0;        // максимальное количество повторений
    int most_frequent = a[0]; // число, которое встречается чаще всего
    // Перебираем каждый элемент массива
    for(int i = 0; i < size; i++)
    {
        int count = 0;
        // Считаем, сколько раз a[i] встречается в массиве
        for(int j = 0; j < size; j++)
        {
            if(a[i] == a[j])
                count++;
        }
        // Если текущее число встречается больше всех предыдущих
        if(count > max_count)
        {
            max_count = count;
            most_frequent = a[i];
        }
    }
    return most_frequent;
}
int main()
{

    int arr[SIZE]= {0};
    Input(arr,SIZE);
    // Выводим число, которое встречается чаще всего
    printf("%d\n", Digit_most_frequentint (arr, SIZE));
    return 0;
}
