/* exercise3.c -- Chapter 11 */
#include <stdio.h>          // for getchar()
#include <ctype.h>          // for isspace()
#include <stdbool.h>        // for bool, true, false
#include <string.h>         // for strlen()

#define SIZE (10 + 1)

char * str_word(char * str, int n);

int main(void)
{
    char str[SIZE];
    char * ptr;

    ptr = str_word(str, SIZE);
    puts(ptr);

    printf("The length of the string \"%s\" is %lu.\n", ptr, strlen(ptr));
    
    return 0;
}

/* reads (SIZE - 1) characters because the last character is '\0' */
char * str_word(char * str, int n)
{
    bool inword = false;
    int i = 0;
    char temp;

    while (i < n - 1 && (temp = getchar()) != EOF)
    {
        if (!inword && !isspace(temp))
            inword = true;
        else if (inword && !isspace(temp))
            str[i++] = temp;
        else if (inword && isspace(temp))
            break;
    }
    if (EOF == temp)
        str = NULL;
    else    // it is important for any string in the C
        str[i] = '\0';  // if (i == n - 1)

    return str;
}
