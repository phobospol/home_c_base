#include <stdio.h>
//Составить функцию, которая преобразует текущий символ цифры в число. Написать программу считающую сумму цифр в тексте. int digit_to_num(char c)
int digit_to_num(char c);

int main()
{
    char c;
    int sum = 0;

    while ((c = getchar()) != '.')//Читаем символы до точки
    {   
        sum += digit_to_num(c);//считаем сумму цифр в тексте
    }

    printf("%d\n", sum);

    return 0;
}

int digit_to_num(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';//Если символ — цифра, она преобразуется в число
    return 0;//Если не цифра — возвращается 0
}
