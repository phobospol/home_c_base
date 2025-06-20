#include <stdio.h>
#include <inttypes.h>
// Считать массив из 12 элементов и посчитать среднее арифметическое элементов массива.
#define SIZE 12

int Input(int arr[], int n)
{
    int i;
    for(i=0; i<n; i++)
        scanf("%d",&arr[i]);
    return i;
}
void Print(int *arr,int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

float Mult(int arr[],int len,int k)
{
    int i;
    float sum=0;
    float sr=0;
    for (i = 0; i < len; i++)
        sum+=arr[i];
    sr=sum/k;
    return sr;
}

int main(int argc, char **argv)
{
    int arr[SIZE]= {0};
    Input(arr,SIZE);
    int coef=SIZE;
    Mult(arr,SIZE,coef);
    printf ("%0.2f", Mult(arr,SIZE,coef));
    return 0;
}
