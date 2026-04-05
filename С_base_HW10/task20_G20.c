#include <stdio.h>
#include <string.h>

// Считать предложение из файла input.txt и определить можно ли из английских букв предложения записанного в файле получить одно слово - палиндром. Ответ напечатать на стандартный поток вывода. Требуется реализовать логическую функцию и применить ее.is_palindrom(string)

#define MAX_LENGTH 1000
#define ALPHABET_SIZE 26

// Логическая функция: проверяет, можно ли из букв строки составить палиндром
int is_palindrome(const char *str)
{
    int freq[ALPHABET_SIZE] = {0};  // Массив частот букв (a-z)
    int odd_count = 0;  // Количество букв с нечётной частотой
    int i;

    // Подсчитываем частоту каждой буквы, игнорируя пробелы
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z') 
        {
            freq[str[i] - 'a']++;
        }
    }

    // Считаем количество букв с нечётной частотой
    for (i = 0; i < ALPHABET_SIZE; i++)
    {
        if (freq[i] % 2 == 1) {
            odd_count++;
        }
    }

    // Палиндром можно составить, если нечётных букв 0 или 1
    return (odd_count <= 1);
}

int main(int argc, char **argv)
{
    FILE *inputfile;
    char sentence[MAX_LENGTH];

    // Открываем файлы
    inputfile = fopen ("input.txt", "r");
    if (inputfile == NULL)
    {
        perror("Could not open input.txt\n");
        fclose (inputfile);
        return 1;
    }

    // Читаем строку из input.txt
    if (fgets (sentence, MAX_LENGTH, inputfile) == NULL)
    {
        perror("File input.txt empty or a reading error occurred\n");
        fclose (inputfile);
        return 1;
    }

    // Удаляем символ новой строки, если он есть
    size_t len = strlen (sentence);
    if (len > 0 && sentence [len-1] == '\n')
    {
        sentence [len-1] = '\0';
    }

    // Применяем функцию проверки возможности составления палиндрома
    if (is_palindrome(sentence)) 
    {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    // Закрываем файлы
    fclose (inputfile);

    return 0;
}
