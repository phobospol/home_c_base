#include <stdio.h>
#include <string.h>
/*Цифры по возрастанию
Написать функцию и программу демонстрирующую работу данной функции. Вывести в порядке возрастания цифры, входящие в десятичную запись натурального числа N, не более 1000 цифр. Цифра пробел сколько раз данная цифра встречается в числе.
*/
void count_digits(const char* number_str)
{
    int counts[10] = {0};

    // Подсчёт цифр
    for (int i = 0; number_str[i] != '\0'; i++) {
        if (number_str[i] >= '0' && number_str[i] <= '9') {
            counts[number_str[i] - '0']++;
        }
    }

    // Вывод результата
    for (int i = 0; i < 10; i++) {
        if (counts[i] > 0) {
            printf("%d %d\n", i, counts[i]);
        }
    }
}

int main()
{
    char number[1001];  // максимум 1000 цифр + '\0'
    scanf("%1000s", number);
    count_digits(number);
    return 0;
}
