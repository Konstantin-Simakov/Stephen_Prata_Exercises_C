/* exercise2.c -- Chapter 9 */
#include <stdio.h>
#include <ctype.h>

#define SPACE ' '

void chline(char ch, int i, int j);
void get_two_int(int *, int *);

int main(void)
{
    int ch;
    int low, up;

    printf("Enter one character (or <Enter> to finish the program):\n");
    while ((ch = getchar()) != '\n')
    {
        printf("Enter two integers:\n");
        get_two_int(&low, &up);
        while (low > up && low < 1)
        {
            printf("The first number is not more or equal than the second.\n");
            printf("And the first number is not less than 1. Try again:\n");
            get_two_int(&low, &up);
        }

        chline(ch, low, up);        /* desired function is working */
        putchar('\n');

        printf("Enter a character (or <Enter> to finish the program):\n");
    }
    printf("The program has been completed.\n");
    
    return 0;
}

/* desired function */
void chline(char ch, int i, int j)
{
    int col;        /* column number */

    for (col = 1; col < i; col++)
        printf("%c", SPACE);

    for (col = i; col <= j; col++)
        printf("%c", ch);
}

/* gets two integers */
void get_two_int(int * plow, int * pup)
{
    char ch;

    while (scanf("%d %d", plow, pup) != 2)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not integers. Enter two integers again:\n");
    }
    /* and skip the rest of the line including '\n' */
    while (getchar() != '\n')   
        continue;
}
