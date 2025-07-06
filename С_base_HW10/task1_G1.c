#include <stdio.h>
#include <string.h>
//В файле input.txt дана строка. Вывести ее в файл output.txt три раза через запятую и показать количество символов в ней.

int main() {
    FILE *infile, *outfile;
    char str[1001]; // Буфер до 1000 символов + '\0'

    // Открываем input.txt для чтения
    infile = fopen("input.txt", "r");
    if (infile == NULL) {
        perror("Could not open input.txt");
        return 1;
    }

    // Считываем строку из файла
    if (fgets(str, sizeof(str), infile) == NULL) {
        perror("Error reading from input.txt");
        fclose(infile);
        return 1;
    }
    fclose(infile);

    // Удаляем символ новой строки, если он есть
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--; // уменьшаем длину, чтобы не учитывать \n
    }

    // Открываем output.txt для записи
    outfile = fopen("output.txt", "w");
    if (outfile == NULL) {
        perror("Could not open output.txt");
        return 1;
    }

    // Записываем строку три раза через запятую, записываем количество символов
    fprintf(outfile, "%s, %s, %s %zu\n", str, str, str, len);

    fclose(outfile);

    return 0;
}
