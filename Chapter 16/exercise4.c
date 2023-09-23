/* exercise4.c -- Chapter 16 */
#include <stdio.h>
#include <time.h>       /* for clock_t, clock(), CLOCKS_PER_SEC */

unsigned long long loop_per_sec(double seconds);

int main(void)
{
    double sec;

    puts("Enter the number of seconds:");
    while (scanf("%lf", &sec) == 1)
    {
        printf("The loop iteration number is %llu\n", loop_per_sec(sec));
        puts("Enter the next number of seconds:");
    }
    puts("Bye!");
    
    return 0;
}

unsigned long long loop_per_sec(double seconds)
{
    unsigned long long num = 0;

    /* the first calling of clock() function -- returns a number of CPU time units */
    const clock_t end = clock() + seconds * CLOCKS_PER_SEC;

    while (clock() < end)
        num++;

    return num;
}
