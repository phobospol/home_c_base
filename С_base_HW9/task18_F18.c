//*
#include <stdio.h>

//Дана целочисленная квадратная матрица 10 х 10. реализовать алгоритм вычисления суммы максимальных элементов из каждой строки. Напечатать значение этой суммы. Предполагается, что в каждой строке такой элемент единственный. Реализовать функцию поиска максимума в строке из 10 элементов

void Input(int SIZE, int a[][SIZE]) // ввод матрицы
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}
//*/
int max_in_row (int a[], int size) // функция поиска максимального элемента в строке
{
    int max = a[0];

    for(int i = 1; i < size; i++)
    {
        if(a[i] > max)
            max = a[i];
    }

    return max;
}
/*
void Print(int n, int a[])
{
    for (int i = 0; i < n; i++)
        printf("%d ",a[i]);
    printf("\n");
}
*/
//*
int main()
{
    enum {BUFFER_SIZE = 10};
    int input[BUFFER_SIZE][BUFFER_SIZE]; // входной массив
    int sum = 0;
    Input(BUFFER_SIZE,input);
      
    for(int i = 0; i < BUFFER_SIZE; i++) // поиск максимума в каждой строке
    {
        sum += max_in_row(input[i], BUFFER_SIZE);
    }
    printf("%d\n", sum);

    return 0;
}
//*/




