/* exercise3.c -- Chapter 2 */
#include <stdio.h>

int main(void)
{
    /* instead age = 23 may be written any other number */
    int age;
    int days;
    
    age = 23;
    days = age * 365;

    printf("Your age (in days) = %d", days);
    
    return 0;
}
