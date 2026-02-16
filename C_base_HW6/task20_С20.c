#include <stdio.h>
//Проверить строку состоящую из скобок "(" и ")" на корректность.
int main()
{
    char c;
    int count = 0;  // счётчик открытых скобок

    while ((c = getchar()) != '.')//Читаем символы до точки
    {
        if (c == '(')
        {
            count++;//count++ при встрече (
        }
        else if (c == ')')
        {
            count--;//count-- при встрече )
            if (count < 0)// если закрывающих больше, чем открывающих → ошибка
            {
                printf("NO\n");
                return 0;
            }
        }
    }

    if (count == 0)
        printf("YES\n");//если количество ( = )
    else
        printf("NO\n");//в противном случае

    return 0;
}
