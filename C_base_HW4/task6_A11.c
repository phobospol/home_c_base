#include <stdio.h>

int main(void)
{
	 int a, b, c, d, e, max, min; //Объявить переменные
    scanf ("%d%d%d%d%d", &a, &b, &c, &d, &e); //Считать пять целых чисел и записать их по адресу a,b,с,d,e
    max = a>b?a:b; //определяем наибольшее число из двух целых чисел a b
    max = max>c?max:c; //определяем наибольшее число из двух целых чисел определенного ранее max и с
    max = max>d?max:d; //определяем наибольшее число из двух целых чисел определенного ранее max и d
    max = max>e?max:e; //определяем наибольшее число из двух целых чисел определенного ранее max и e
    min = a<b?a:b; //определяем наименьшее число из двух целых чисел a b
    min = min<c?min:c; //определяем наименьшее число из двух целых чисел определенного ранее main и с
    min = min<d?min:d; //определяем наименьшее число из двух целых чисел определенного ранее min и d
    min = min<e?min:e; //определяем наименьшее число из двух целых чисел определенного ранее min и e
    printf("%d\n", max+min); //Вывести на экран сумму наибольшего и наименьшего чисел
	return 0;
}
