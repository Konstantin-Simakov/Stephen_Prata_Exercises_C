/* exercise13.c --  Chapter 10
                    compilation: 
                    gcc exercise13.c sup_mod13.c -o exercse13 -Wall 

                    launch the program in Linux system: 
                    ./exercise13
*/
#include <stdio.h>
#include "head13.h"

int main(void)
{
    double array[ROWS][COLS];

    input(array, ROWS);
    show_results(array, ROWS);

    return 0;
}
