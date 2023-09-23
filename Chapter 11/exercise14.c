/* exercise14.c -- Chapter 11 */
#include <stdio.h>
#include <stdlib.h>     // for atof() -- double, atoi() -- int

double power(double base, int exponent);

int main(int argc, char ** argv)
{
    double base;        // for atof() -- double
    int n;              // for atoi() -- int

    if (argc < 3)
        printf("Application: %s double-number integer-positive-number\n", argv[0]);
    else
    {
        base = atof(argv[1]);
        n = atoi(argv[2]);
        printf("Number: base = %.2f, exponent = %d.\n"
            "The power of this number is %.2f\n", base, n, power(base, n));
    }

    return 0;
}

/* for positive exponent only (for now...) */
double power(double base, int n)
{
    int i;
    double res;

    if (n < 0)
    {
        n = -n;
        for (i = 1, res = 1; i <= n; i++)
            res *= base;
        res = 1 / res;
    }
    else if (n > 0)
        for (i = 1, res = 1; i <= n; i++)
            res *= base;
    else if (base != 0)
            res = 1;
    else    // else if (0 == base)
    {
        printf("Result undefined.\n");
        res = 1;
    }


    return res;
}
