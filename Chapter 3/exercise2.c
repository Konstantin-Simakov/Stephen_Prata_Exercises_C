/* exercise2.c -- Chapter 3 */
#include <stdio.h>

int main(void)
{
    signed char ch = 0;

    printf("Please, enter your number from 0 to 127: ");
    scanf("%hhd", &ch);
    
    printf("Your entered number %hhd is according %c\n", ch, ch);

    return 0;
}
