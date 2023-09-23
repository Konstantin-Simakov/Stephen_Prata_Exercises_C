/* exercise1.c -- Chapter 3 */
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    int type_overflow = INT_MAX;
    long int type = LONG_MIN;
    long long type2 = LLONG_MAX;
    unsigned long long type3 = ULLONG_MAX;
    float type_overflow_1 = FLT_MAX;
    float epsilon = FLT_EPSILON;
    float min_val_fl = FLT_MIN;
    // etc...
    // there is a lot of types which can be overflowed by sum operation...

    printf("1.------------------------------------------------\n");
    printf("%d\n%ld\n%lld\n%llu\n%f\n%f\n%f\n", type_overflow, type, type2, type3, type_overflow_1, epsilon, min_val_fl);
    printf("2.------------------------------------------------\n");
    printf("%d\n%ld\n%lld\n%llu\n%f\n%f\n%f\n", type_overflow + 1, type - 1, type2 + 1, type3 + 1, 
        type_overflow_1 + 1, epsilon, min_val_fl - 1);
        // here      ^^^^^^^  nothing change

    return 0;
}
