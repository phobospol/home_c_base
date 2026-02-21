#include <stdio.h>
//Дана монотонная последовательность, в которой каждое натуральное число k встречается ровно k раз: 1, 2, 2, 3, 3, 3, 4, 4, 4, 4,… Выведите первые n членов этой последовательности.
void monotonus_sequence(int n, int k, int count)//функция для печати монотонной последовательности
{
    if (count == n)
        return;

    for (int i = 0; i < k && count < n; i++)//цикл для печати числа k не больше k раз, но не больше n
    {
        printf("%d ", k);
        count++;
    }

    monotonus_sequence(n, k + 1, count);//рекурсивная функция
}

int main()
{
    int n;
    scanf("%d", &n);

    monotonus_sequence(n, 1, 0);

    return 0;
}

