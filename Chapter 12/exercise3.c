/* exercise3.c -- Chapter 12 */
/* (pe12-3b.c) */
/* compile with pe12-3a.c */
/* compilation: 
gcc exercise3.c pe12-3a.c -o exercise3 -Wall */
/* run on any Debian based Linux system: 
./exercise3 */
#include <stdio.h>
#include "pe12-3a.h"

int main(void)
{
    int mode;
    int res_mode = 0;                       /* initial value for the res_mode (default) -- for correct job of functions below */

    printf("Enter 0 for metric mode or 1 for American mode: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        res_mode = set_mode(mode, res_mode);    /* here is res_mode == previous mode -- for the 2nd argument of set_mode() */
        show_info(res_mode);

        printf("Enter 0 for metric mode or 1 for American mode "
            " (-1 to finish): ");
        scanf("%d", &mode);
    }
    printf("The program has been completed.\n");
    
    return 0;
}
