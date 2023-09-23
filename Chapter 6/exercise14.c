/* exercise14.c (the 1-st version) -- Chapter 6 */
#include <stdio.h>

#define SIZE 8

int main(void)
{
    double ar1[SIZE], ar2[SIZE];        // acceptably!
    int i;

    // the first array ar1 initialization
    printf("Please enter 8 double numbers: ");
    for (i = 0; i < SIZE; i++)
        scanf("%lf", &ar1[i]);

    // the second array ar2 initialization
    ar2[0] = ar1[0];
    for (i = 1; i < SIZE; i++)
        ar2[i] = ar2[i - 1] + ar1[i];

    // output of both arrays
    for (i = 0; i < SIZE; i++)
        printf("%5.2f ", ar1[i]);
    printf("\n");

    for (i = 0; i < SIZE; i++)
        printf("%5.2f ", ar2[i]);
    printf("\n");

    // notification of the end of the program
    printf("The program has been completed...\n");

    return 0;
}
