#include <stdio.h>
#include <stdlib.h>

/*Считать число N из файла input.txt. Сформировать строку из N символов. N четное число, не превосходящее 26. На четных позициях должны находится четные цифры в порядке возрастания, кроме 0, на нечетных позициях - заглавные буквы в порядке следования в английском алфавите. Результат записать в файл output.txt
*/

int main() {
    FILE *infile, *outfile;
    int N;

    // Открытие input.txt для чтения
    infile = fopen("input.txt", "r");
    if (infile == NULL) {
        printf("Could not open file input.txt");
        return 1;
    }

    if (fscanf(infile, "%d", &N) != 1) {
        printf("Error reading a number from a file input.txt");
        fclose(infile);
        return 1;
    }
    fclose(infile);

    // Проверка допустимого значения N
    if (N <= 0 || N > 26 || N % 2 != 0) {
        printf("Error: N must be an even number between 2 and 26");
        return 1;
    }

    char result[27]; // максимум 26 символов + '\0'
    int letter = 'A';
    int even_digits[] = {2, 4, 6, 8};
    int digit_index = 0;

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            result[i] = (char)letter++;
        } else {
            result[i] = (char)(even_digits[digit_index] + '0');
            digit_index = (digit_index + 1) % 4; // повторяем цикл 2-4-6-8
        }
    }
    result[N] = '\0';

    // Запись в output.txt
    outfile = fopen("output.txt", "w");
    if (outfile == NULL) {
        printf("Could not open file  output.txt");
        return 1;
    }

    fprintf(outfile, "%s\n", result);
    fclose(outfile);

    return 0;
}
