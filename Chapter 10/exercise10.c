/* exercise10.c -- Chapter 10 */
/* compilation: 
gcc exercise10.c sup_mod10.c -o exercise10 -Wall */
#include <stdio.h>
#include "head10.h"

int main(void)
{
    int ar1[SIZE] = {1, 3, 5, 7};
    int ar2[SIZE] = {2, 4, 6, 8};
    int ar3[SIZE];

    sum_arrs(ar3, ar1, ar2, SIZE);
    
    printf("The first array:\n");
    show_arr(ar1, SIZE);
    
    printf("The second array:\n");
    show_arr(ar2, SIZE);

    printf("The third array whose contents are "
        "the sum of two previous arrays.\n");
    show_arr(ar3, SIZE);
    
    return 0;
}
