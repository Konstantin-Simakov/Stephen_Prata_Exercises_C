/* exercise9.c -- Chapter 10 */
#include <stdio.h>

#define SIZE1 3
#define SIZE2 5

void copy_arr(int rows, int cols, double target[rows][cols], 
                const double source[rows][cols]);
void show_arr(int rows, int cols, const double array[rows][cols]);

int main(void)
{
    double ar1[SIZE1][SIZE2];
    double ar2[SIZE1][SIZE2];
    int i, j;

    for (i = 0; i < SIZE1; i++)
        for (j = 0; j < SIZE2; j++)
            ar1[i][j] = i + j * j;      // arbitrary initialization of the ar1

    copy_arr(SIZE1, SIZE2, ar2, ar1);

    printf("\t\t\t\tSource array:\n");
    show_arr(SIZE1, SIZE2, ar1);
    printf("\t\t\t\tTarget array:\n");
    show_arr(SIZE1, SIZE2, ar2);
    
    return 0;
}

void copy_arr(int rs, int cs, double t[rs][cs], 
                const double s[rs][cs])
{
    int i, j;

    for (i = 0; i < rs; i++)
        for (j = 0; j < cs; j++)
            t[i][j] = s[i][j];
}

void show_arr(int rs, int cs, const double ar[rs][cs])
{
    int i, j;

    for (i = 0; i < rs; i++)
        for (j = 0; j < cs; j++)
            printf("%.2f ", ar[i][j]);
    putchar('\n');
}
