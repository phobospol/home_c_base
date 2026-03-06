#include <stdio.h>

//Вывести в порядке следования цифры, входящие в десятичную запись натурального числа N.

#define SIZE 20

long long Input(void)

{
    long long i;
    scanf("%lld",&i);
    return i;
}

void Numbers_in_order (int N, int a[])

{
    int i = 0;
    // разделить число на цифры через строку.
    while (N > 0)
    {
        a[i] = N % 10;
        N /= 10;
        i++;
    }
    // вывести цифры в порядке следования
    for(int j = i - 1; j >= 0; j--)
    {
        printf("%d ", a[j]);
    }
}

int main()
{
    int arr[SIZE]= {0};
    long long i = Input();
    Numbers_in_order (i, arr);
    return 0;
}
