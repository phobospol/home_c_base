
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// В файле input.txt дано предложение. Необходимо заменить все имена «Cao» на «Ling» и записать результат в файл output.txt.

#define MAX_LENGTH 1000

// Функция для замены подстроки oldstr на newstr в строке str

void replace_all (char *str, const char *oldstr, const char *newstr)
{
    char buffer [MAX_LENGTH];
    char *pos;
    size_t old_len = strlen (oldstr);

    // При помощи цикла while bщем в строке str все подстроки "Cao"
    while ((pos = strstr (str, oldstr)) != NULL)
    {
        // Копируем начало строки до найденной подстроки "Cao" в buffer
        strncpy (buffer, str, pos - str);
        buffer [pos - str] = '\0';

        // Добавляем новую подстроку "Ling" в buffer
        strcat (buffer, newstr);

        // Добавляем оставшуюся часть строки после замененной подстроки в buffer
        strcat (buffer, pos + old_len);

        // Копируем buffer обратно в исходную строку str
        strcpy (str, buffer);
    }
}

int main(int argc, char **argv)
{
    FILE *inputfile, *outputfile;
    char sentence[MAX_LENGTH];

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
    if (fgets (sentence, MAX_LENGTH, inputfile) == NULL)
    {
        perror("File input.txt empty or a reading error occurred\n");
        fclose (inputfile);
        fclose (outputfile);
        return 1;
    }

    // Удаляем символ новой строки, если он есть
    size_t len = strlen (sentence);
    if (len > 0 && sentence [len-1] == '\n')
    {
        sentence [len-1] = '\0';
    }

    // Заменяем все подстроки "Cao" на "ling"
    replace_all (sentence, "Cao", "Ling");

    // Записываем результат в output.txt
    fprintf(outputfile, "%s\n", sentence);

    // Закрываем файлы
    fclose (inputfile);
    fclose (outputfile);

    return 0;
}


#include <stdio.h>
#include <string.h>

// В файле input.txt дано предложение. Необходимо заменить все имена «Cao» на «Ling» и записать результат в файл output.txt.

#define MAX_LENGTH 5000

// Функция для замены всех вхождений "Cao" на "Ling" в строке
void replace_all_Cao_to_Ling(char *str, size_t max_len)
{
    char buffer[MAX_LENGTH];
    size_t i = 0; // индекс в исходной строке
    size_t j = 0; // индекс в буфере

    while (str[i] != '\0' && j < max_len - 1)
    {
        // Если встречаем последовательность "Cao"
        if (str[i] == 'C' && str[i+1] == 'a' && str[i+2] == 'o')
        {
            // Проверка переполнения буфера
            if (j + 4 >= max_len) break;

            buffer[j++] = 'L';
            buffer[j++] = 'i';
            buffer[j++] = 'n';
            buffer[j++] = 'g';

            i += 3; // пропускаем заменяемые символы
        } else {
            buffer[j++] = str[i++];
        }
    }

    buffer[j] = '\0';
    strcpy(str, buffer); // копируем результат обратно в исходную строку
}

int main()
{
    FILE *inputfile = fopen("input.txt", "r");
    if (!inputfile) {
        perror("Could not open input.txt");
        return 1;
    }

    FILE *outputfile = fopen("output.txt", "w");
    if (!outputfile) {
        perror("Could not open output.txt");
        fclose(inputfile);
        return 1;
    }

    char sentence[MAX_LENGTH];

    while (fgets(sentence, sizeof(sentence), inputfile)) {
        // Убираем символ новой строки
        size_t len = strlen(sentence);
        if (len > 0 && sentence[len-1] == '\n') {
            sentence[len-1] = '\0';
        }

        // Заменяем все "Cao" на "Ling"
        replace_all_Cao_to_Ling(sentence, MAX_LENGTH);

        // Записываем в файл
        fprintf(outputfile, "%s\n", sentence);
    }

    fclose(inputfile);
    fclose(outputfile);

    return 0;
}
*/

#include <stdio.h>
#include <string.h>

// В файле input.txt дано предложение. Необходимо заменить все имена «Cao» на «Ling» и записать результат в файл output.txt.

#define MAX_LENGTH 5000  // максимальная длина строки

// Универсальная функция замены всех вхождений oldstr на newstr
void replace_all_safe(char *str, size_t max_len, const char *oldstr, const char *newstr) 
{
    char buffer[MAX_LENGTH];
    size_t i = 0; // индекс в исходной строке
    size_t j = 0; // индекс в буфере
    size_t old_len = strlen(oldstr);
    size_t new_len = strlen(newstr);

    while (str[i] != '\0' && j < max_len - 1) 
    {
        // Проверяем, есть ли в текущей позиции oldstr
        if (strncmp(&str[i], oldstr, old_len) == 0) 
        {
            // Проверка переполнения буфера
            if (j + new_len >= max_len) break;

            // Копируем newstr в буфер
            memcpy(&buffer[j], newstr, new_len);
            j += new_len;
            i += old_len;
        } else {
            buffer[j++] = str[i++];
        }
    }

    buffer[j] = '\0';
    strcpy(str, buffer);
}

int main() {
    FILE *inputfile = fopen("input.txt", "r");
    if (!inputfile) {
        perror("Could not open input.txt");
        return 1;
    }

    FILE *outputfile = fopen("output.txt", "w");
    if (!outputfile) {
        perror("Could not open output.txt");
        fclose(inputfile);
        return 1;
    }

    char sentence[MAX_LENGTH];

    while (fgets(sentence, sizeof(sentence), inputfile)) 
    {
        // Убираем символ новой строки
        size_t len = strlen(sentence);
        if (len > 0 && sentence[len-1] == '\n') 
        {
            sentence[len-1] = '\0';
        }

        // Пример: заменяем Cao на Ling
        replace_all_safe(sentence, MAX_LENGTH, "Cao", "Ling");

        fprintf(outputfile, "%s\n", sentence);
    }

    fclose(inputfile);
    fclose(outputfile);

    return 0;
}
