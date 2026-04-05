#include <stdio.h>
#include <string.h>

//Разработать функцию дана строка из маленьких английских букв. Составить из символов палиндром максимальной длинны. При составлении палиндрома буквы в палиндроме должны быть расположены в лексикографическом порядке. Записать ответ в файл output.txt.

#define MAX_LENGTH 1000
#define ALPHABET_SIZE 26

// Функция для составления палиндрома максимальной длины в лексикографическом порядке
void make_max_palindrome(char *input, char *result) 
{
    int freq[ALPHABET_SIZE] = {0};  // Массив частот букв (a-z)
    int i, j, mid_char = -1;

    // Подсчитываем частоту каждой буквы
    for (i = 0; input[i] != '\0'; i++) 
    {
        if (input[i] >= 'a' && input[i] <= 'z') {
            freq[input[i] - 'a']++;
        }
    }

    // Формируем первую половину палиндрома (и центр, если есть нечётная буква)
    j = 0;
    for (i = 0; i < ALPHABET_SIZE; i++) 
    {
        // Добавляем половину парных букв (в лексикографическом порядке)
        int pairs = freq[i] / 2;
        for (int k = 0; k < pairs; k++) 
        {
            result[j++] = 'a' + i;
        }

        // Запоминаем самую маленькую букву с нечётной частотой для центра
        if (freq[i] % 2 == 1 && mid_char == -1) 
        {
            mid_char = i;
        }
    }

    // Сохраняем длину первой половины
    int half_len = j;

    // Если есть буква с нечётной частотой, добавляем её в центр
    if (mid_char != -1) 
    {
        result[j++] = 'a' + mid_char;
    }

    // Добавляем вторую половину (зеркальное отражение первой половины)
    for (i = half_len - 1; i >= 0; i--) 
    {
        result[j++] = result[i];
    }

    // Завершаем строку нулевым терминатором
    result[j] = '\0';
}


int main(int argc, char **argv)
{
    FILE *inputfile, *outputfile;
    char input[MAX_LENGTH];
    char palindrome[MAX_LENGTH];

    // Открываем файлы
    inputfile = fopen ("input.txt", "r");
    if (inputfile == NULL)
    {
        perror("Could not open input.txt\n");
        fclose (inputfile);
        return 1;
    }
    outputfile = fopen ("output.txt", "w");
    if (outputfile == NULL)
    {
        perror("Could not open output.txt\n");
        fclose (outputfile);
        return 1;
    }
    // Читаем строку из input.txt
    if (fgets (input, MAX_LENGTH, inputfile) == NULL)
    {
        perror("File input.txt empty or a reading error occurred\n");
        fclose (inputfile);
        fclose (outputfile);
        return 1;
    }

    // Удаляем символ новой строки, если он есть
    size_t len = strlen (input);
    if (len > 0 && input [len-1] == '\n')
    {
        input [len-1] = '\0';
    }

    // Создаём палиндром максимальной длины
    make_max_palindrome(input, palindrome);



    // Записываем результат в output.txt
    fprintf(outputfile, "%s\n", palindrome);

    // Закрываем файлы
    fclose (inputfile);
    fclose (outputfile);

    return 0;
}
