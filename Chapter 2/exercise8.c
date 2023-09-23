/* exercise8.c -- Chapter 2 */
#include <stdio.h>

void one_three(void);
void two(void);

int main(void)
{
    printf("Begin now:\n");
    one_three();
    printf("Excellent!\n");
    
    return 0;
}

/* here you can uncomment these comment below; nothing will change */
void one_three(void)
{
    printf("One\n");
    two();
    printf("Three\n");
}

void two(void)
{
    printf("Two\n");
}
