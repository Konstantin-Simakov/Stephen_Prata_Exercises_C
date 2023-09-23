/* exercise2.c -- Chapter 15 */
#include <stdio.h>
#include <stdlib.h>         /* for exit(), EXIT_FAILURE */
#include <stdbool.h>        /* for bool, true, false */
#include <limits.h>         /* for CHAR_BIT */
#include <string.h>         /* for strlen() */
#include <math.h>           /* for pow(); add "-lm" option during the compilation */

bool is_bin(char * str);
int bstoi(char *);
char * itobs(int num, char * str, int n);

int main(int argc, char * argv[])
{
    /* here you can change the sizeof() value if you change integer type */
    const static int SIZE = CHAR_BIT * sizeof(signed char) + 1;
    int num1, num2;
    char bin_str1[SIZE], bin_str2[SIZE];

    if (argc != 3)
    {
        puts("Incorrect number of arguments!!!");
        printf("Usage: %s <%s> <%s>\n", argv[0], "bin_str", "bin_str");
        exit(EXIT_FAILURE);
    }

    if (!is_bin(argv[1]) || !is_bin(argv[2]))
    {
        puts("Not a binary string; only 0, 1 can be entered.");
        printf("Usage: %s <%s> <%s>\n", argv[0], "bin_str", "bin_str");
        exit(EXIT_FAILURE);
    }
    else if (strlen(argv[1]) > SIZE - 1 || strlen(argv[2]) > SIZE - 1)
    {
        printf("Too long binary string. String length can be no more than %d.\n", SIZE - 1);
        printf("Usage: %s <%s> <%s>\n", argv[0], "bin_str", "bin_str");
        exit(EXIT_FAILURE);
    }

    num1 = bstoi(argv[1]);
    num2 = bstoi(argv[2]);

    putchar('\n');
    printf("~(%s) = %s\n", 
        argv[1], itobs(~num1, bin_str1, SIZE));                     // 1
    printf("~(%s) = %s\n", 
        argv[2], itobs(~num2, bin_str2, SIZE));                     // 2

    putchar('\n');
    printf("(%s) & (%s) = %s\n", 
        argv[1], argv[2], itobs(num1 & num2, bin_str1, SIZE));      // 3
    printf("(%s) | (%s) = %s\n", 
        argv[1], argv[2], itobs(num1 | num2, bin_str1, SIZE));      // 4
    printf("(%s) ^ (%s) = %s\n", 
        argv[1], argv[2], itobs(num1 ^ num2, bin_str1, SIZE));      // 5

    putchar('\n');
    puts("The program has been completed.");
    
    return 0;
}

bool is_bin(char * str)
{
    bool is_bs = true;

    while (*str)
    {
        if ('0' == *str || '1' == *str)
            str++;
        else
        {
            is_bs = false;
            break;
        }
    }

    return is_bs;
}

int bstoi(char * str)
{
    const int MAX_POWER = strlen(str) - 1;
    int i;
    int res;

    for (res = 0, i = 0; i <= MAX_POWER; i++)
    {
        if ('1' == str[i])
            res += pow(2, MAX_POWER - i);
    }

    return res;
}

char * itobs(int num, char * str, int n)
{
    int i;

    for (i = n - 2; i >= 0; i--, num >>= 1)
        str[i] = (num & 0x1) + '0';
    str[n - 1] = '\0';

    return str;
}
