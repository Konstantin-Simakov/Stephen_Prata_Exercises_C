/* pe12-3a.c -- Chapter 12 */
/* (pe12-3b.c) */
/* compile with exercise3.c */
/* compilation: 
gcc exercise3.c pe12-3a.c -o exercise3 -Wall */
/* run on any Debian based Linux system: 
./exercise3 */
#include <stdio.h>      /* for scanf(), printf() */

static void get_info(int, double *, double *);      // this function declaration is needed

int set_mode(int mode, int prev_mode)
{
    int res_mode = mode;

    if (mode >= 2)
    {
        if (0 == prev_mode)
            printf("Invalid mode specified. Mode 0 (EU) is being used.\n");
        else if (1 == prev_mode)
            printf("Invalid mode specified. Mode 1 (US) is being used.\n");
        res_mode = prev_mode;
    }

    return res_mode;
}

static void get_info(int mode, double * distance, double * consumption)
{
    if (0 == mode)
    {
        printf("Enter the distance traveled in kilometers: ");
        scanf("%lf", distance);
        printf("Enter the amount of fuel consumed in liters: ");
        scanf("%lf", consumption);
    }
    else if (1 == mode)
    {
        printf("Enter the distance traveled in miles: ");
        scanf("%lf", distance);
        printf("Enter the amount of fuel consumed in gallons: ");
        scanf("%lf", consumption);
    }
}

void show_info(int mode)
{
    double distance, consumption;

    get_info(mode, &distance, &consumption);

    if (1 == mode)
        printf("Fuel consumption is %.1f mpg.\n", 
            distance / consumption);
    else if (0 == mode)
        printf("Fuel consumption is %.2f liters per 100 kilometers.\n", 
            consumption / (distance / 100));
}
