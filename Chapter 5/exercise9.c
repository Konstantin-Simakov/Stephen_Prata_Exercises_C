/* exercise9.c -- Chapter 5 */
#include <stdio.h>

void temperatures(double fahr);

int main(void)
{
    double fahr;

    printf("This program converts Fahrenheit into Kelvin and Celsius.\n");

    printf("Please enter the Fahrenheit value "
        "(or q to exit the program): ");
    while (scanf("%lf", &fahr) == 1)            // %lf for double to scanf()
    {                                           // scanf() is used once in this program in this ^^^ case
        temperatures(fahr);                     // calculates Celsius, Kelvin from Fahrenheit

        printf("Please enter the next Fahrenheit value "
            "(or q to exit the program): ");
    }
    printf("OK. Good bye!\n");

    return 0;
}

void temperatures(double fahr)
{
    const float CELS_1 = 5.0f / 9.0f;           // the first coefficient for Celsius
    const float CELS_2 = 32.0f;                 // the second coefficient for Celsius
    const float KELV_1 = 273.16f;               // the first and only coefficient for Kelvin

    double kelv, cels;

    cels = CELS_1 * (fahr - CELS_2);
    kelv = cels + KELV_1;

    printf("%10.2f F %10.2f C %10.2f K\n", fahr, cels, kelv);
}
