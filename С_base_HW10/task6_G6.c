#include <stdio.h>
#include <string.h>

//В файле input.txt символьная строка не более 1000 символов. Необходимо проверить, является ли она палиндромом (палиндром читается одинаково в обоих направлениях). Реализовать логическую функцию is_palindrom(str) и записать ответ в файл output.txt.

// Логическая функция проверки палиндрома
int is_palindrom(const char *str) 
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) 
        {
            return 0; // НЕ палиндром
        }
    }
    return 1; // Палиндром
}

int main() 
{
    FILE *infile, *outfile;
    char str[1001]; // до 1000 символов + '\0'

    // Открытие input.txt
    infile = fopen("input.txt", "r");
    if (infile == NULL) {
        printf("Could not open input.txt");
        return 1;
    }

    // Чтение строки
    if (fgets(str, sizeof(str), infile) == NULL) 
    {
        printf("Error reading from input.txt");
        fclose(infile);
        return 1;
    }
    fclose(infile);

    // Удаляем символ новой строки, если он есть
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') 
    {
        str[len - 1] = '\0';
    }

    // Проверка и запись результата
    outfile = fopen("output.txt", "w");
    if (outfile == NULL) 
    {
        printf("Could not open output.txt");
        return 1;
    }

    if (is_palindrom(str)) 
    {
        fprintf(outfile, "YES\n");
    } else {
        fprintf(outfile, "NO\n");
    }

    fclose(outfile);
    return 0;
}
