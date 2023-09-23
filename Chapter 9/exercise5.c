/* exercise5.c -- Chapter 9 */
#include <stdio.h>

void larger_of(double * x, double * y);

int main(void)
{
    double x, y;

    x = 5.0;
    y = 6.0;                /* y is more than x */

    printf("Firstly x = %.2f, y = %.2f\n", x, y);

    larger_of(&x, &y);      /* assigns y value to x */

    printf("Now x = %.2f, y = %.2f\n", x, y);
    
    return 0;
}

void larger_of(double * x, double * y)
{
    if (*x < *y)
        *x = *y;
    else
        *y = *x;
}
