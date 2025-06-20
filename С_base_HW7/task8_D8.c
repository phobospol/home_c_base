#include <stdio.h>
#include <inttypes.h>

#define SIZE 5

int Input(int arr[], int n)
{
    int i;
    for(i=0; i<n; i++)
        scanf("%d",&arr[i]);
    return i;
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
    printf ("%0.3f", Mult(arr,SIZE,coef));
    return 0;
}
