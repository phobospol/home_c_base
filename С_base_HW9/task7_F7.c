//#include <stdio.h>
/*
Написать функцию, которая сжимает серии массива, состоящего из единиц и нулей по следующему принципу: например, массив [0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1] преобразуется в [4,7,2,4] (т.к. начинается с нуля, то сразу записывается количество элементов первой серии); а массив [1,1,1,0,0,0,0,0,0,0] преобразуется в [0,3,7] (т.к. первая серия - это единицы, то первый элемент преобразованного массива 0).Необходимо реализовать только одну функцию, всю программу загружать не надо. Прототип функции: int compression(int a[], int b[], int N)
*/
/*
int Input(int n, int a[])
{
    int i;
    for(i=0; i< n; i++)
        scanf("%d",&a[i]);
    return i;
}
*/
int compression(int a[], int b[], int N)
{
    if (N <= 0) return 0;

    int out_index = 0;
    int i = 0;

    // Если первая серия — 1, добавляем 0 в начало выходного массива
    if (a[0] == 1) {
        b[out_index++] = 0;
    }

    while (i < N) {
        int current = a[i];
        int count = 0;

        // Подсчёт длины текущей серии
        while (i < N && a[i] == current) {
            count++;
            i++;
        }

        b[out_index++] = count;
    }

    return out_index; // Возвращаем размер выходного массива
}
/*
void Print(int n, int a[])
{
    for (int i = 0; i < n; i++)
        printf("%d ",a[i]);
    printf("\n");
}

int main()
{
    enum {BUFFER_SIZE =10};
    int input[BUFFER_SIZE]; // входной массив
    int output[100]; // выходной массив для результата
    Input(BUFFER_SIZE,input);
    Print(BUFFER_SIZE,input);
    for (int i = 0; i < compression(input,output,BUFFER_SIZE); i++) {
        printf("%d ", output[i]);
    }
    printf("\n");
    return 0;
}
*/
