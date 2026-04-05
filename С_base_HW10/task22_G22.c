
#include <stdio.h>
#include <string.h>

/* Известный алгоритм Soundex (https://ru.wikipedia.org/wiki/Soundex) определяет, похожи ли два английских слова по звучанию. На вход он принимает слово и заменяет его на некоторый четырёхсимвольный код. Если коды двух слов совпадают, то слова, как правило, звучат похоже.

Вам требуется реализовать этот алгоритм. Он работает так:

Первая буква слова сохраняется.
В остальной части слова:
буквы, обозначающие, как правило, гласные звуки: a, e, h, i, o, u, w и y — отбрасываются; оставшиеся буквы (согласные) заменяются на цифры от 1 до 6, причём похожим по звучанию буквам соответствуют одинаковые цифры:
1: b, f, p, v
2: c, g, j, k, q, s, x, z
3: d, t
4: l
5: m, n
6: r
Любая последовательность одинаковых цифр сокращается до одной такой цифры. Итоговая строка обрезается до первых четырёх символов. Если длина строки меньше требуемой, недостающие символы заменяются знаком 0.
Примеры:
аmmonium → ammnm → a5555 → a5 → a500
implementation → implmnttn → i51455335 → i514535 → i514
*/


// Функция для получения кода буквы
char get_code(char c)
{
    switch (c)
    {
    case 'b':
    case 'f':
    case 'p':
    case 'v':
        return '1';
    case 'c':
    case 'g':
    case 'j':
    case 'k':
    case 'q':
    case 's':
    case 'x':
    case 'z':
        return '2';
    case 'd':
    case 't':
        return '3';
    case 'l':
        return '4';
    case 'm':
    case 'n':
        return '5';
    case 'r':
        return '6';
    default:
        return '0'; // гласные и прочие
    }
}

int main()
{
    FILE *inputfile = fopen("input.txt", "r");
    FILE *outputfile = fopen("output.txt", "w");

    if (!inputfile || !outputfile)
    {
        return 1;
    }

    char word[25];
    fscanf(inputfile, "%s", word);

    char result[5]; // 4 символа + '\0'
    int res_len = 0;

    // 1. Первая буква сохраняется
    result[res_len++] = word[0];

    // ВАЖНО: НЕ используем код первой буквы
    char prev_code = '0';

    // 2. Обработка остальных букв
    for (int i = 1; word[i] != '\0'; i++)
    {
        char code = get_code(word[i]);

        // пропускаем гласные (code == '0')
        if (code == '0')
            continue;

        // убираем подряд одинаковые цифры
        if (code != prev_code)
        {
            result[res_len++] = code;
        }

        prev_code = code;

        // если уже 4 символа — можно остановиться
        if (res_len == 4)
            break;
    }

    // 3. Дополняем нулями
    while (res_len < 4)
    {
        result[res_len++] = '0';
    }

    result[4] = '\0';

    fprintf(outputfile, "%s", result);

    fclose(inputfile);
    fclose(outputfile);

    return 0;
}
