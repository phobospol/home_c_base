#include <stdio.h>

int main(void)
{
	 int a, b, c, max; //Объявить переменные
    scanf ("%d%d%d", &a, &b, &c); //Считать три целых числа и записать их по адресу a,b,с
    max = a>b?a:b; //определяем максимальное число из двух целых чисел a b
    max = max>c?max:c; //определяем максимальное число из двух целых чисел определенного ранее max и с
    printf("%d\n", max); //Вывести на экран наибольшее целое число
	return 0;
}
