/* exercise7.c -- Chapter 10 */
#include <stdio.h>

#define SIZE1 2
#define SIZE2 5

void copy_arr(double * tar, const double * source, int n);

int main(void)
{
    const double source[SIZE1][SIZE2] = {
        {1.0, 3.0, 5.0, 7.0, 9.0}, 
        {2.0, 4.0, 6.0, 8.0, 10.0}
    };
    double target[SIZE1][SIZE2];
    int i, j;

    printf("\t\tThe source array:\n");
    for (i = 0; i < SIZE1; i++)
        for (j = 0; j < SIZE2; j++)
            printf("%.2f ", source[i][j]);
    putchar('\n');  
    putchar('\n');  

    for (i = 0; i < SIZE1; i++)
        copy_arr(target[i], source[i], SIZE2);

    printf("\t\tThe target array:\n");
    for (i = 0; i < SIZE1; i++)
        for (j = 0; j < SIZE2; j++)
            printf("%.2f ", target[i][j]);
    putchar('\n');  

    return 0;
}

void copy_arr(double * target, const double * source, int size)
{
    int i;

    for (i = 0; i < size; i++)
        target[i] = source[i];
}
