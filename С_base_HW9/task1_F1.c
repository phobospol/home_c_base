#include <stdio.h>
/*
Сортировка по взрастанию
Написать только одну функцию, которая сортирует массив по возрастанию. Необходимо реализовать только одну функцию, всю программу составлять не надо.
Строго согласно прототипу. Имя функции и все аргументы должны быть: void sort_array(int size, int a[]).
Всю программу загружать не надо, только одну эту функцию. Можно просто закомментировать текст всей программы, кроме данной функции.
*/

/*
int Input(int size, int a[])
{
    int i;
    for(i=0; i<size; i++)
        scanf("%d",&a[i]);
    return i;
}
*/

void sort_array(int size, int a[])
{
    int i= 0;
    int j = 0;
    int temp = 0;
    for(i = 0; i < size; ++i)
    {
        for(j = i; j < size; ++j)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
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
    enum {BUFFER_SIZE =20};
    int buffer[BUFFER_SIZE];

    Input(BUFFER_SIZE,buffer);
    Print(BUFFER_SIZE,buffer);

    sort_array(BUFFER_SIZE,buffer);
    Print(BUFFER_SIZE,buffer);
    return 0;
}
*/

