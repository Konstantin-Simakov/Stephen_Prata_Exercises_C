/* exercise4.c -- Chapter 5 */
#include <stdio.h>

const float INCH_CM = 2.54f;                    // cm number per one inch
const int FOOT_INCH = 12;                       // inches number per one foot
const float FOOT_CM = INCH_CM * FOOT_INCH;      // cm number per one foot

int main(void)
{
    float cm, inch_left;
    int foot;

    printf("This program converts cm number into feet and inches number.\n");

    printf("Please enter a height in cm "
        "(or <= 0 to exit the program): ");
    scanf("%f", &cm);
    while (cm > 0)
    {
        foot = (int) (cm / FOOT_CM);
        inch_left = (cm / FOOT_CM - foot) * FOOT_INCH;          // == cm % FOOT_CM * FOOT_INCH; if cm has been int type

        printf("%.1f cm = %d feet, %.1f inches\n", cm, foot, inch_left);

        printf("Please enter a height in cm "
            "(or <= 0 to exit the program): ");
        scanf("%f", &cm);
    }
    printf("That\'s all. Good bye!\n");

    return 0;
}
