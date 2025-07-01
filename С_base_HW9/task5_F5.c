//#include <stdio.h>
/*
Написать только одну функцию, которая находит максимальный элемент в массиве. Всю программу загружать не надо.
Прототип функции: int find_max_array(int size, int a[])
*/
/*
int Input(int size, int a[])
{
    int i;
    for(i=0; i< size; i++)
        scanf("%d",&a[i]);
    return i;
}
*/
int find_max_array(int size, int a[])
{
    if (size <= 0) {
        // Обработка ошибки: массив пустой
        return -1; // Или любое другое значение по выбору
    }

    int max = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}
/*
void Print(int size, int a[])
{
    for (int i = 0; i < size; i++)
        printf("%d ",a[i]);
    printf("\n");
}
int main()
{
    enum {BUFFER_SIZE =6};
    int buffer[BUFFER_SIZE];
    Input(BUFFER_SIZE,buffer);
    Print(BUFFER_SIZE,buffer);
    printf("%d\n", find_max_array(BUFFER_SIZE,buffer));
    return 0;
}
*/
