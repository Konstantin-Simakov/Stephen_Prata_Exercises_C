/* exercise3.c -- Chapter 10 */
#include <stdio.h>

int biggest(int ar[], int n);

int main(void)
{
    int ar[] = {5, 6, 7, 8, 12, 9, 10, 11};

    printf("The biggest value from that array is %d\n", 
        biggest(ar, sizeof ar / sizeof ar[0]));
    
    return 0;
}

int biggest(int ar[], int n)
{
    int i;
    int max = ar[0];

    for (i = 1; i < n; i++)
        if (max < ar[i])
            max = ar[i];

    return max;
}
