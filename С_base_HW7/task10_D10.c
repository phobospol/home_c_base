#include <stdio.h>
//Дано натуральное число n ≥ 1. Проверьте, является ли оно простым. Программа должна вывести слово YES, если число простое или NO в противном случае. Необходимо составить рекурсивную функцию и использовать ее int is_prime(int n, int delitel)

int is_prime(int n, int delitel)
{
    if (n == 1)
        return 0;

    if (delitel * delitel > n) // если истина то делителей не найдено число простое возвращаем 1
        return 1;

    if (n % delitel == 0)// если истина число составное возвращаем 0
        return 0;

    return is_prime(n, delitel + 1);// в противном случае проверяем следующий увеличенный на 1 делитель
}

int main()
{
    int n;
    scanf("%d", &n);

    (is_prime(n, 2))? printf("YES\n") : printf("NO\n");// для проверки числа принимаем delitel = 2

    return 0;
}
