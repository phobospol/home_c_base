#include <stdio.h>

//Ввести номер месяца и вывести название времени года.
int main(int argc, char **argv)
{
    int a;//Объявить переменные
    scanf ("%d",&a);//cчитать целое число и записать по адресу a
    printf ("%s",a>=3&&a<=5?"spring":"");//Вывести на экран "spring" если a любое число от 3 до 5 включительно
    printf ("%s",a>=6&&a<=8?"summer":"");//Вывести на экран "summer" если a любое число от 6 до 8 включительно
    printf ("%s",a>=9&&a<=11?"autumn":"");//Вывести на экран "autumn" если a любое число от 9 до 11 включительно
    printf ("%s",(a>=1&&a<=2)||a==12?"winter":"");//Вывести на экран "winter" если a любое число от 1 до 2 включительно или 12
return 0;
}
