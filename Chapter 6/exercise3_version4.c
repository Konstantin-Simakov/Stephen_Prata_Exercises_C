/* exercise3_version4.c -- Chapter 6 */
#include <stdio.h>

#define LETTER 'F'

int main(void) 
{
    int i, j;

    for (i = LETTER; i >= 'A'; i--)
    {
        for (j = LETTER; j >= i; j--)
            printf("%c", j);
        printf("\n");
    }

    return 0;
}
