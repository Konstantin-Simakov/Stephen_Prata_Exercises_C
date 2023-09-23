/* exercise14.c --  Chapter 10
                    compilation: 
                    gcc exercise14.c sup_mod14.c -o exercise14 -Wall 

                    launch the program in Linux system: 
                    ./exercise14
*/
#include <stdio.h>
#include "head14.h"

int main(void)
{
    double array[ROWS][COLS];

    input(ROWS, COLS, array);
    show_results(ROWS, COLS, array);

    return 0;
}
