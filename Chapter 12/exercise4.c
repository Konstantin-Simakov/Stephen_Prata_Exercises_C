/* exercise4.c -- Chapter 12 */
#include <stdio.h>

int native_count(int * count);

int main(void)
{
    int ct = 0;
    int i;

    for (i = 0; i < 10; i++)
    {
        ct = native_count(&ct);
        printf("ct = %d\n", ct);
    }

    printf("The function was called %d times.\n", ct);
    
    return 0;
}

int native_count(int * count)
{
    return ++(*count);
}
