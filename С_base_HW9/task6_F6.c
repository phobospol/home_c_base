//#include <stdio.h>
/*
Написать только одну логическую функцию, которая определяет, верно ли, что среди элементов массива есть два одинаковых. Если ответ «да», функция возвращает 1; если ответ «нет», то 0. Строго согласно прототипу:
int is_two_same(int size, int a[]);
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
int is_two_same(int size, int a[])
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[i] == a[j]) {
                return 1; // Найдена пара одинаковых элементов
            }
        }
    }
    return 0; // Все элементы разные
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
    if (is_two_same(BUFFER_SIZE,buffer)) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}
*/
