/* exercise2.c -- Chapter 16 */
#include <stdio.h>

#define HARMONIC_MEAN(X, Y) (2 / ((1.0 / (X)) + (1.0 / (Y))))

int main(void)
{
    int q, t;       /* it can also be double instead of int -- the result will be double anyway */
    
    q = 5;
    t = 6;

    printf("Harmonic mean of %d and %d is %.2f\n", q, t, HARMONIC_MEAN(q, t));
    
    return 0;
}
