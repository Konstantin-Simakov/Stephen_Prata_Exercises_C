/* exercise6.c -- Chapter 9 */
#include <stdio.h>

void three(double * x, double * y, double * z);

int main(void)
{
    double x, y, z;

    x = 5.0;
    y = 7.0;
    z = 3.0;

    printf("Firstly x = %.2f, y = %.2f and z = %.2f\n", x, y, z);

    three(&x, &y, &z);

    printf("Now     x = %.2f, y = %.2f and z = %.2f\n", x, y, z);
    
    return 0;
}

void three(double * first, double * second, double * third)
{
    double temp;

    // min
    temp = *first;
    if (*first > *second)
    {
        *first = *second;
        *second = temp;
    }

    temp = *first;
    if (*first > *third)
    {
        *first = *third;
        *third = temp;
    }

    // middle and max
    temp = *second;
    if (*second > *third)
    {
        *second = *third;
        *third = temp;
    }
}
