/* exercise6.c -- Chapter 15 */
/* compile with exercise6_support.c */
#include <stdio.h>
#include "exercise6_head.h"     /* for struct template */

int main(void)
{
    struct font text = { 1, 12, 0 };    /* remain values are 0 -- off */
    char choice;

    output_st(&text);
    while ((choice = show_menu()) != 'q')
    {
        switch (choice)
        {
            case 'f': font_id_change(&text); 
                break;
            case 's': size_change(&text);
                break;
            case 'a': align_change(&text);
                break;
            case 'b': bold(&text);
                break;
            case 'i': italic(&text);
                break;
            case 'u': underline(&text);
                break;
            default : puts("Error 1");
        }
        output_st(&text);
    }
    puts("The program has been completed.");
    
    return 0;
}
