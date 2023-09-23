/* exercise14_version2.c -- Chapter 6 */
#include <stdio.h>

#define SIZE 8

int main(void)
{
    double ar1[SIZE], ar2[SIZE];
    int i, j;

    // the first array ar1 initialization
    printf("Please enter 8 double numbers: ");
    for (i = 0; i < SIZE; i++)
        scanf("%lf", &ar1[i]);

    // the second array ar2 initialization
    for (j = 0; j < SIZE; j++)
        ar2[j] = 0;                     // firstly, initializate to zero

    // with nested loop
    for (j = 0; j < SIZE; j++)          //
        for (i = 0; i <= j; i++)        // elements array ar2 calculating
            ar2[j] += ar1[i];           //

    // output of the both arrays
    for (i = 0; i < SIZE; i++)          // firstly, array ar1 output
        printf("%5.3f ", ar1[i]);       // with field width + space character (good tone in the programing (in this case))
    printf("\n");
                                        
    for (j = 0; j < SIZE; j++)          // array ar2 output
        printf("%5.3f ", ar2[j]);       // with field width + space character
    printf("\n");

    // notification of the end of the program
    printf("The program has been completed...\n");

    return 0;
}
