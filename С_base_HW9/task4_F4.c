//#include <stdio.h>
//#include <string.h>
/*
 Написать только одну функцию. Всю программу отправлять не надо. Вывести в порядке возрастания цифры, входящие в строку. Цифра - количество. Функция должно строго соответствовать прототипу:
void print_digit(char s[])
*/
void print_digit(char s[])
{
    int counts[10] = {0}; // Массив для подсчёта каждой цифры

    // Перебираем символы строки
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            counts[s[i] - '0']++;
        }
    }

    // Выводим только те цифры, которые встречаются хотя бы один раз
    for (int i = 0; i < 10; i++) {
        if (counts[i] > 0) {
            printf("%d %d\n", i, counts[i]);
        }
    }
}
/*
int main()
{
    char input[1001]; // До 1000 символов + '\0'
    //fgets(input, sizeof(input), stdin);
    scanf("%[^\n]", input);
    print_digit(input);

    return 0;
}
*/
