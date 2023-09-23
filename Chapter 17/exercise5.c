/* exercise5.c -- Chapter 17                            */
/*                copmile with exercise5_support.c      */
#include <stdio.h>
#include "exercise5.h"
#include <stdlib.h>

int main(void)
{
    Stack string;
    Item ch;        /* there is Item type == char type in this program */

    /* The most important! */
    stack_initialize(&string);

    puts("Enter the string:");
    while ((ch = getchar()) != '\n')
        if (push(&string, &ch) == false)            /* add this character to the string (stack) */
        {
            fputs("push() returns false.\n", stderr);
            exit(EXIT_FAILURE);
        }

    puts("The string in reverse order:");
    while (!stack_is_empty(&string))
    {
        if (pop(&string, &ch) == false)
        {
            fputs("pop() returns false.\n", stderr);
            exit(EXIT_FAILURE);
        }
        putchar(ch);
    }

    empty_the_stack(&string);
    puts("\nBye!");
    
    return 0;
}
