/* exercise7.c -- Chapter 2 */
#include <stdio.h>

void smiling(void);

int main(void)
{
    smiling();
    smiling();
    smiling();
    printf("\n");

    smiling();
    smiling();
    printf("\n");

    smiling();
    printf("\n");

    return 0;
}

void smiling(void)
{
    printf("Smiling! ");
}
