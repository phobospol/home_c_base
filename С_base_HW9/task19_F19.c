//*
#include <stdio.h>

//Определить количество положительных элементов квадратной матрицы, превышающих по величине среднее арифметическое всех элементов главной диагонали. Реализовать функцию среднее арифметическое главной диагонали.

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
// функция среднего арифметического главной диагонали
double avg_diag (int SIZE, int a[][SIZE])
{
    int sum = 0;

    for(int i = 0; i < SIZE; i++)
    {
        sum += a[i][i];
    }

    return (double)sum / SIZE;
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
    int count = 0;
    Input(BUFFER_SIZE,input);
    double avg = avg_diag (BUFFER_SIZE, input);

    for(int i = 0; i < BUFFER_SIZE; i++) // подсчет элементов
    {
        for(int j = 0; j < BUFFER_SIZE; j++)
        {
            if(input[i][j] > 0 && input[i][j] > avg)
            {
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;

}
//*/

