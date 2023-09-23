/* exercise18.c -- Chapter 6 */
#include <stdio.h>

#define DUNBAR  150     // Dunbar number
#define START   5       // days number per 1 week

int main(void)
{
    int friends = START;
    int week = 1;

    printf("The number of friends at the end of the %d week is %d.\n", 
            week, friends);
    while (friends <= DUNBAR)
    {
        friends = (friends - week) * 2;
        week++;

        printf("The number of friends at the end of the %d week is %d.\n", 
            week, friends);
    }
    printf("Dunbar's number %d has been reached...\n", DUNBAR);

    return 0;
}
