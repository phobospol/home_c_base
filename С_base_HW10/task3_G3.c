#include <stdio.h>
#include <string.h>

//В файле input.txt дана строка из не более 1000 символов. Показать номера символов, совпадающих с последним символом строки.
//Результат записать в файл output.txt

int main() {
    FILE *infile, *outfile;
    char str[1001]; // максимум 1000 символов + '\0'
    int i, len;
    char last_char;

    // Открываем input.txt
    infile = fopen("input.txt", "r");
    if (infile == NULL) {
        printf("Could not open input.txt");
        return 1;
    }

    // Считываем строку
    if (fgets(str, sizeof(str), infile) == NULL) {
        printf("Line reading error");
        fclose(infile);
        return 1;
    }
    fclose(infile);

    // Удалим возможный символ новой строки '\n' в конце
    len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    // Если строка пустая
    if (len == 0) {
        printf("The line is empty.\n");
        return 1;
    }

    last_char = str[len - 1];

    // Открываем output.txt
    outfile = fopen("output.txt", "w");
    if (outfile == NULL) {
        printf("Could not open output.txt");
        return 1;
    }

    // Проходим по строке и ищем совпадения
    for (i = 0; i < len-1; i++) {
        if (str[i] == last_char) {
            fprintf(outfile, "%d ", i);
        }
    }

    fclose(outfile);
    return 0;
}

