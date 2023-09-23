/* exercise6.c -- Chapter 10 */
#include <stdio.h>

#define SIZE 6

/* reverses the order of the contents of the array */
void exchange(double ar[], int n);

int main(void)
{
    double ar[SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int i;

    printf("Before array exchanges:\n");
    for (i = 0; i < SIZE; i++)
        printf("%.2f ", ar[i]);
    putchar('\n');

    exchange(ar, SIZE);

    printf("After array exchanges:\n");
    for (i = 0; i < SIZE; i++)
        printf("%.2f ", ar[i]);
    putchar('\n');

    return 0;
}

void exchange(double ar[], int n)
{
    double temp;
    int i;

    for (i = 0; i < n / 2; i++)
    {
        temp = ar[i];
        ar[i] = ar[n - 1 - i];
        ar[n - 1 - i] = temp;
    }
}
