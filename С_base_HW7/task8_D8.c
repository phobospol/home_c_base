#include <stdio.h>
//Составить рекурсивную функцию, Выведите все числа от a до b включительно, в порядке возрастания, если a < b, или в порядке убывания в противном случае
void print_range(int a, int b)
{
    printf("%d ", a);//печатает текущее число

    if (a == b)//Если a == b вывести одно число a и завершить.
        return;

    if (a < b)//Если a < b → вывести a и вызвать функцию print_range для A+1.
        print_range(a + 1, b);
    else
        print_range(a - 1, b);// в противном случае вывести а и вызвать функцию print_range для A-1
}

int main()
{
    int c, d;
    scanf("%d %d", &c, &d);

    print_range(c, d);

    return 0;
}
