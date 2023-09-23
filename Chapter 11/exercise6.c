/* exercise6. -- Chapter 11 */
#include <stdio.h>
#include <stdbool.h>        // for bool, true, false

#define SIZE 100

bool is_within(const char * s, int c);
char * s_gets(char * str, int n);
int get_char(void);

int main(void)
{
    char str[SIZE];
    int ch;

    puts("Enter the string:");
    while (s_gets(str, SIZE) && str[0])
    {
        puts("Enter the character that needs to be find:");
        ch = get_char();
        if (is_within(str, ch))
            printf("The character \'%c\' consists in the string.\n", ch);
        else
            printf("The character \'%c\' doesn't consist in the string.\n", ch);

        puts("Enter the next string (or an empty string "
            "to finish the program)");
    }
    puts("The program has been completed.");

    return 0;
}

bool is_within(const char * s, int c)
{
    bool in_str;

    while (*s != c && *s)
        s++;        // search!!! this character
    
    // proccessing of this character
    if (!*s)
        in_str = false;
    else
        in_str = true;

    return in_str;
}

char * s_gets(char * str, int n)
{
    char * ret_val;

    ret_val = fgets(str, n, stdin);

    if (ret_val)
    {
        while (*str != '\n' && *str != '\0')
            str++;

        if ('\n' == *str)
            *str = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}

int get_char(void)
{
    int ch;

    while ((ch = getchar()) == '\n')    // discard '\n' character
        puts("Unrecognized character \'\\n\'. Try again:");
    while (getchar() != '\n')           // discard the rest line after correct input character
        continue;

    return ch;
}
