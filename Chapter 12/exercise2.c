/* exercise2.c -- Chapter 12 */
/* (pe12-2b.c) */
/* compile with pe12-2a.c */
/* compilation: 
gcc exercise2.c pe12-2a.c -o exercise2 -Wall */
/* run on any Debian based Linux system: 
./exercise2 */
#include <stdio.h>
#include "pe12-2a.h"

int main(void)
{
    int mode;

    printf("Enter 0 for metric mode or 1 for American mode: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        set_mode(mode);
        get_info();
        show_info();

        printf("Enter 0 for metric mode or 1 for American mode "
            " (-1 to finish): ");
        scanf("%d", &mode);
    }
    printf("The program has been compldeted.\n");
    
    return 0;
}
