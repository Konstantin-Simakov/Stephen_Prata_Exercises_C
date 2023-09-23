/* exercise10.c -- Chapter 11 */
#include <stdio.h>
#include <ctype.h>      /* for isspace() */

#define SIZE 40         /* you can change this value but it should be only positive */

char * s_gets(char *, int);
void str_delete_space(char *);

int main(void)
{
    char str[SIZE];

    puts("Enter a string (or an empty string to finish the program):");
    while (s_gets(str, SIZE) && str[0])
    {
        str_delete_space(str);
        puts(str);

        puts("Enter a string (or an empty string to finish the program):");
    }
    puts("The program has been completed.");
    
    return 0;
}

void str_delete_space(char * str)
{
    char * temp;

    while (*str)
    {
        if (isspace(*str))
        {
            temp = str;
            while (*temp)
            {
                *temp = *(temp + 1);    /* the '\0' character is accounted for here */
                temp++;
            }
            continue;                   /* if string consists of more than 1 space character */
        }
        str++;
    }
}

char * s_gets(char * st, int n)
{
    char * ret_val;

    ret_val = fgets(st, n, stdin);

    if (ret_val)
    {
        while (*st != '\n' && *st)
            st++;

        if ('\n' == *st)
            *st = '\0';
        else    // if ('\0' == *st)
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}
