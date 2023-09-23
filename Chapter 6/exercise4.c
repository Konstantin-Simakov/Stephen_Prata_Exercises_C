/* exercise4.c -- Chapter 6 */ 
/* if your system supports ASCII encoding, this program will work 
otherwise you should look at the 2nd version of this program (in this directory) */
/* It isn't profitable to organize the interactivity of the program 
using the scanf () and printf () functions... */
#include <stdio.h>

#define R_AND_C 6       /* the number of rows and columns in the program ouput */

int main(void)
{
    int i, j;
    char ch = 'A';

    for (i = 0; i < R_AND_C; i++)
    {
        for (j = 0; j <= i; j++)
            printf("%c", ch++);
        printf("\n");
    }

    return 0;
}
