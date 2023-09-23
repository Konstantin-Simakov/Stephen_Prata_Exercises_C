/* exercise10.c -- Chapter 6 */
#include <stdio.h>

long sum_squares(int a, int b);     // function prototype

int main(void)
{
    int lower, upper;       // 2 variable for main() function as fact arguments
    long result;

    printf("Please enter lower and upper limits: ");    // the invitation is like in the author's book
    scanf("%d %d", &lower, &upper);
    while (lower < upper)
    {
        result = sum_squares(lower, upper);
        printf("The sum of the squares of integers from %d to %d is %ld\n", 
            lower, upper, result);

        printf("Please enter the following limits combination: ");
        scanf("%d %d", &lower, &upper);
    }
    printf("The work has been completed\n");

    return 0;
}

long sum_squares(int a, int b)      // formal parameters
{
    int num;
    long sum = 0L;      // 0 (zero) long int type for long int sum variable

    for (num = a; num <= b; num++)      // number is used as counter
        sum += num * num;               // 2 operators in 1

    return sum;
}

/* NOTES!!! */
