#include <stdio.h>
//Ввести целое число и определить, верно ли, что в его записи есть две одинаковые цифры, стоящие рядом.
int main(int argc, char **argv)
{
    int a;//Объявить переменные
    scanf ("%d",&a);//cчитать целое число и записать по адресу a
    // Используя цикл for
    int i,count=0;
    for(i=a; a!=0; i++) {
        if ((a/10)%10==a%10) {
            count=1;
        }
        a=a/10;
    }
    count==1?printf("YES"):printf("NO");// Используя тернарные операции
    //вывести на печать "YES" если в числе две одинаковые цифры стоящие
    // рядом "NO" в противном случае
    return 0;
}

