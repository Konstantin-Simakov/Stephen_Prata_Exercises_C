/* exercise9.c -- Chapter 9 */
#include <stdio.h>

double power(double, int);

int main(void)
{
    double result;
    double base;
    int expon;

    printf("Enter the base and exponent and I will "
        "calculate the result of the exponentiation:\n");
    while (scanf("%lf %d", &base, &expon) == 2)
    {
        result = power(base, expon);
        printf("The power of %.2f in %d is %.5f\n", 
            base, expon, result);

        printf("Enter the next base and exponent combination and "
            "I will calculate the result of the exponentiation "
            "(or q to finish the program):\n");
    }
    printf("The program has been completed.\n");
    
    return 0;
}

double power(double base, int n)
{
    double res;

    res = 1.0;      // for 2 cases

    if (base != 0)
    {
        if (n > 0)
            res = base * power(base, n - 1);        // == res previous
        else if (n < 0)
            res = 1 / base * power(base, n + 1);
    }
    else
        if (n == 0)
            printf("The result of raising 0 to the 0 power is undefined.\n");
        else
            res = 0.0;

    return res;
}
