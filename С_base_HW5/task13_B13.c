#include <stdio.h>
//Посчитать количество четных и нечетных цифр числа.
int main(int argc, char **argv)
{
    int a;//Объявить переменную A
    scanf ("%d",&a);//cчитать целое число и записать по адресу A
    // Используя цикл for
    int i, even_numb=0, odd_numb=0;
    for(i=a; a!=0; i++) {
        if ((a%10)%2==0) {
            even_numb++;
        }
        else {
            odd_numb++;
        }
        a/=10;
    }
    printf("%d %d",even_numb,odd_numb);//вывести на печать количество четных и нечетных чисел
    return 0;
}

