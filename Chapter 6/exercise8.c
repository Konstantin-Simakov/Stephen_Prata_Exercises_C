/* exercise8.c -- Chapter 6 */
#include <stdio.h>

int main(void)
{
    double f1, f2;
    double res;         // calculating result

    printf("Enter 2 floating numbers (f1 and f2; "
        "or q to exit the program): ");
    while (scanf("%lf %lf", &f1, &f2) == 2)
    {
        res = (f1 - f2) / (f1 * f2);
        printf("(f1 - f2) / (f1 * f2) = %.3f\n", res);

        printf("Enter the next 2 floating numbers (f1 and f2; "
            "or q to exit the program): ");
    }
    printf("Good bye!\n")

    return 0;
}
