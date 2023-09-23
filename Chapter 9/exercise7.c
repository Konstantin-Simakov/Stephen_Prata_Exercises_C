/* exercise7.c -- Chapter 9 */
#include <stdio.h>
#include <ctype.h>              /* for isalpha() */

int char_number(int ch);        /* int ch -- for EOF == (-1) */

int main(void)
{
    int ch;
    int ans;        /* for char_number() answer */

    printf("Enter a character (or <Ctrl+D> "
        "to finish the program):\n");
    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n')
            continue;

        // char_number() using
        ans = char_number(ch);
        if (ans == -1)
            printf("This character is not letter.\n");
        else
            printf("The serial number of this letter is %d.\n", 
            ans);

        printf("Enter a character (or <Ctrl+D> "
            "to finish the program):\n");
    }
    printf("The program has been completed.\n");
    
    return 0;
}

/* only for ASCII-code table */
int char_number(int ch)
{
    int ser_num;        /* a serial number of the letter */

    if (isupper(ch))
        ser_num = ch - 'A' + 1;
    else if (islower(ch))
        ser_num = ch - 'a' + 1;
    else
        ser_num = -1;

    return ser_num;
}
