#include <stdio.h>
//Ввести два целых числа a и b (a ≤ b) и вывести сумму квадратов всех чисел от a до b.
int main(int argc, char **argv)
{
    int a, b, sum=0;//Объявить переменные
    scanf ("%d%d",&a,&b);//cчитать целые числа и записать по адресу a b
    if (a<=b)
    {
        // Используя цикл for
        int i;
        for(i=a; i<=b; i++) {
            sum+=i*i;
        }
        printf("%d ",sum);//вывести на печать сумму квадратов всех чисел от a до b.
    }
    else
    {
        printf("Error:(%d>%d)",a,b);//вывести на печать сообщение об ошибке если а > b
    }
    return 0;
}


