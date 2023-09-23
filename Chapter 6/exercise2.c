/* exercise2.c -- Chapter 6 */
#include <stdio.h>

#define SIZE 5      // isosceles dollar-sign triangle -- output

int main(void)
{
    int i, j;

    for (i = 1; i <= SIZE; i++)
    {
        for (j = 1; j <= i; j++)
            printf("$");
        printf("\n");
    }

    return 0;
}
