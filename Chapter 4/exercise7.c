/* exercise7.c -- Chapter 4 */
#include <stdio.h>
#include <float.h>

int main(void)
{
    double doub = 1.0 / 3.0;
    float fl = 1.0f / 3.0f;

    printf("\nOutput:\n");
    printf("---------------------------------------\n");
    /* table header */
    printf("%-20s %-20s\n", "double", "float");
    /* the table itself */  
    printf("%-20.4f %-20.4f\n", doub, fl);
    printf("%-20.12f %-20.12f\n", doub, fl);
    printf("%-20.16f %-20.16f\n", doub, fl);
    printf("---------------------------------------\n");
    printf("DBL_DIG = %d, FLT_DIG = %d.\n", DBL_DIG, FLT_DIG);

    /* Conclusion: the derived values are inconsistent. */

    return 0;
}
