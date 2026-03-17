//*
#include <stdio.h>

//Составить функцию которая находит след матрицы в двумерном массиве. Показать пример ее работы на матрице из 5 на 5 элементов. След матрицы - это сумма элементов на главной диагонали.

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
// функция вычисления следа матрицы
int trace_matrix (int SIZE, int a[][SIZE])
{
    int sum = 0;

    for(int i = 0; i < SIZE; i++)
    {
        sum += a[i][i];
    }

    return sum;
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
    enum {BUFFER_SIZE = 5};
    int input[BUFFER_SIZE][BUFFER_SIZE]; // входной массив
    Input(BUFFER_SIZE,input);
    printf("%d\n",trace_matrix (BUFFER_SIZE, input));

    return 0;
}
//*/


