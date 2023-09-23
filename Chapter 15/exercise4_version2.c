/* exercise4_version2.c -- Chapter 15 */
#include <stdio.h>
#include <stdlib.h>         /* for exit(), EXIT_FAILURE */
#include <limits.h>         /* for CHAR_BIT */
#include <stdbool.h>        /* for bool, true, false */
#include <math.h>           /* for pow(); add "-lm" option before to compile */

bool bit_include(int num, int pos);

int main(void)
{
    int num, pos;

    num = 8;
    pos = 31;

    if (bit_include(num, pos))
        printf("In the number %d, the bits in position %d are on.\n", num, pos);
    else
        printf("In the number %d, the bits in position %d are off.\n", num, pos);   
    
    return 0;
}

bool bit_include(int num, int pos)
{
    const static int MAX_POS = CHAR_BIT * sizeof(int) - 1;
    int mask;
    bool include = false;

    if (pos < 0 || pos > MAX_POS)
    {
        puts("Invalid position was entered.");
        puts("The program has been completed.");
        exit(EXIT_FAILURE);
    }

    mask = pow(2, pos);             // the 3rd variant
    if ((num & mask) == mask)
        include = true;

    return include;
}
