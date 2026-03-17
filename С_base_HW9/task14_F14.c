/*
#include <stdio.h>

//Составить функцию которая возвращает сумму элементов в заданном отрезке [from, to] для массива.Прототип функции int sum_between_ab(int from, int to, int size, int a[])

void Input(int n, int a[])
{
    for(int i=0; i< n; i++)
        scanf("%d",&a[i]);
}
*/
/*
// Функция sum_between_ab возвращает сумму элементов массива, которые находятся в диапазоне [from, to]
int sum_between_ab (int from, int to, int size, int a[])
{
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        if(a[i] >= from && a[i] <= to)
            sum += a[i];
    }
    return sum;
}
*/
// Функция sum_between_ab которая считает сумму только уникальных чисел в интервале [from, to],то есть если число встречается несколько раз — учитываем его только один раз.
int sum_between_ab (int from, int to, int size, int a[])
{
    int sum = 0;
    if(from > to)// если from > to, то меняем местами from и to в интервале иначе условие проверки вхождения чисел в интервал никогда не выполниться 
    {
        int temp = from;
        from = to;
        to = temp;
    }

    for(int i = 0; i < size; i++)
    {
        if(a[i] >= from && a[i] <= to) // Берём только числа из интервала [from,to].
        {
            int unique = 1;

            for(int j = 0; j < i; j++) //Проверяем уникальность

            {
                if(a[i] == a[j]) //Сравниваем число со всеми предыдущими элементами
                {
                    unique = 0; //Если нашли такое же то unique = 0
                    break;
                }
            }

            if(unique) //Если число уникальное то добавляем его в сумму
                sum += a[i];
        }
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

/*
int main()
{
    enum {BUFFER_SIZE = 12};
    int input[BUFFER_SIZE]; // входной массив
    int from = 0, to = 2;
    Input(BUFFER_SIZE,input);
    printf("%d\n",sum_between_ab (from, to, BUFFER_SIZE, input));

    return 0;
}
*/
