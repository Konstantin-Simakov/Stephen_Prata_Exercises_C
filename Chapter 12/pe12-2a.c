/* pe12-2a.c */
/* compile with exercise2.c */
/* compilation: 
gcc exercise2.c pe12-2a.c -o exercise2 -Wall */
/* run on any Debian based Linux system: 
./exercise2 */
#include <stdio.h>              /* for scanf(), printf() */

static int mode_input = 0;      /* explicit initialization of the static variable to a zero */
static double distance;         /* implicit initialization of the static variable to a zero */
static double consumption;      /* implicit initialization of the static variable to a zero */

void set_mode(int mode)
{
    if (mode >= 2)                      /* automatic variable -- mode */
    {
        if (0 == mode_input)            /* global static variable -- mode_input */
            printf("Invalid mode specified. "
                "Mode 0 (EU) is being used.\n");
        else if (1 == mode_input)       /* global static variable -- mode_input */
            printf("Invalid mode specified. "
                "Mode 1 (US) is being used.\n");
    }
    else
        mode_input = mode;
}

void get_info(void)
{
    if (0 == mode_input)
    {
        printf("Enter the distance traveled in kilometers: ");
        scanf("%lf", &distance);
        printf("Enter the amount of fuel consumed in liters: ");
        scanf("%lf", &consumption);
    }
    else if (1 == mode_input)
    {
        printf("Enter the distance traveled in miles: ");
        scanf("%lf", &distance);
        printf("Enter the amount of fuel consumed in gallons: ");
        scanf("%lf", &consumption);
    }
}

void show_info(void)
{
    if (1 == mode_input)
        printf("Fuel consumption is %.1f mpg.\n", 
            distance / consumption);
    else if (0 == mode_input)
        printf("Fuel consumption is %.2f liters per 100 kilometers.\n", 
            consumption / (distance / 100));
}
