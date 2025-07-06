#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//В файле input.txt даны два слова не более 100 символов каждое, разделенные одним пробелом. Найдите только те символы слов, которые встречаются в обоих словах только один раз. Напечатайте их через пробел в файл output.txt в лексикографическом порядке.

int main() {
    FILE *infile, *outfile;
    char word1[101], word2[101];
    int freq1[26] = {0}, freq2[26] = {0};
    char result[27]; // максимум 26 букв + \0
    int res_index = 0;

    // Открытие input.txt
    infile = fopen("input.txt", "r");
    if (infile == NULL) {
        printf("Couid not open input.txt");
        return 1;
    }

    // Чтение двух слов
    if (fscanf(infile, "%100s %100s", word1, word2) != 2) {
        printf("Error: two words separated by a space were expected.\n");
        fclose(infile);
        return 1;
    }
    fclose(infile);

    // Подсчет частот букв для первого слова
    for (int i = 0; word1[i] != '\0'; i++) {
        freq1[word1[i] - 'a']++;
    }

    // Подсчет частот букв для второго слова
    for (int i = 0; word2[i] != '\0'; i++) {
        freq2[word2[i] - 'a']++;
    }

    // Поиск букв, встречающихся ровно 1 раз в каждом слове
    for (int i = 0; i < 26; i++) {
        if (freq1[i] == 1 && freq2[i] == 1) {
            result[res_index++] = (char)(i + 'a');
        }
    }
    result[res_index] = '\0';

    // Запись результата в output.txt
    outfile = fopen("output.txt", "w");
    if (outfile == NULL) {
        printf("Couid not open output.txt");
        return 1;
    }

    // Печать букв через пробел
    for (int i = 0; i < res_index; i++) {
        fprintf(outfile, "%c", result[i]);
        if (i < res_index - 1) {
            fprintf(outfile, " ");
        }
    }
    fprintf(outfile, "\n");

    fclose(outfile);
    return 0;
}

