//#include <stdio.h>
/*Четные в начало
Написать только одну функцию, которая ставит в начало массива все четные элементы, а в конец – все нечетные. Не нарушайте порядок следования чисел между собой. Строго согласно прототипу:
void sort_even_odd(int n, int a[])
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
void sort_even_odd(int n, int a[])
{
    int temp[n];
    int i, j = 0;

    // Сначала копируем чётные, сохраняя порядок
    for (i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            temp[j++] = a[i];
        }
    }

    // Затем копируем нечётные, сохраняя порядок
    for (i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            temp[j++] = a[i];
        }
    }

    // Копируем результат обратно в исходный массив
    for (i = 0; i < n; i++) {
        a[i] = temp[i];
    }
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
    enum {BUFFER_SIZE =20};
    int buffer[BUFFER_SIZE];
    Input(BUFFER_SIZE,buffer);
    Print(BUFFER_SIZE,buffer);
    sort_even_odd(BUFFER_SIZE,buffer);
    Print(BUFFER_SIZE,buffer);
    return 0;
}
*/
