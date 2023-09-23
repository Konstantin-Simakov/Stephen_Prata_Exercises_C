/* exercise4.c -- Chapter 7 */
#include <stdio.h>

#define PERIOD '.'
#define EXCLAM '!'

int main(void)
{
    char ch;
    int period_count = 0;           // one exlamation mark counter
    int exclam_count = 0;           // two exlamation mark counter

    printf("Enter the text:\n");
    while ((ch = getchar()) != '#')
    {
        if (PERIOD == ch)
        {
            ch = EXCLAM;            // all is correctly
            putchar(ch);
            period_count++;
        }
        else if (EXCLAM == ch)
        {
            putchar(ch);
            putchar(ch);
            exclam_count++;
        }
        else
            putchar(ch);
    }
    printf("The number of substitutions made for a point is %d.\n", 
        period_count);
    printf("The number of substitutions made for one exclamation mark is %d.\n", 
        exclam_count);
    printf("The total number of replacements made is %d.\n", 
        period_count + exclam_count);

    return 0;
}
