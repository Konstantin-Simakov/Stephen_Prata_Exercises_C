// matrix.c -- working with matrices 
#include <stdio.h>
#include <stdlib.h>             // For srand()          
#include <time.h>               // For time()                                       
#include "matrix.h"             // For prototypes and constants 

int main(void)
{
    int matrix_r[ROWS][COLS];   // Automatic (regular, fixed size) matrix.  
    int ** matrix_d;            // Dynamic (resizable) matrix.            
    int * matrix_l;             // Linear (1-dimensional) matrix.   
    int rows = ROWS;            // For dynamic allocated matrices.
    int cols = COLS;            // For dynamic allocated matrices.        

    // The calls time(0) and time(NULL) are equivalent
    srand(time(0));             // For randomizing the seed.

    // Processing (working with) a regular matrix: 
    /*_________________________________________________________________________*/
    init_regular(matrix_r, ROWS);
    print_regular(matrix_r, ROWS);

    swap_rows_regular(matrix_r, ROWS, 1, 2);
    puts("After swapping rows 1 and 2:");
    print_regular(matrix_r, ROWS);

    swap_cols_regular(matrix_r, ROWS, 1, 2);
    puts("After swapping columns 1 and 2:");
    print_regular(matrix_r, ROWS);
    /*_________________________________________________________________________*/

    // Processing (working with) a dynamic matrix:
    /*_________________________________________________________________________*/
    matrix_d = create_dynamic(rows, cols);
    
    init_dynamic(matrix_d, rows, cols);
    print_dynamic(matrix_d, rows, cols);

    swap_rows_dynamic(matrix_d, rows, 1, 2);
    puts("After swapping rows 1 and 2:");
    print_dynamic(matrix_d, rows, cols);

    swap_cols_dynamic(matrix_d, rows, cols, 1, 6);
    puts("After swapping columns 1 and 6:");
    print_dynamic(matrix_d, rows, cols);

    // When transposing a matrix, the number of rows and columns may change, 
    // so this function is realized only for dynamic matrices, not regular.
    transpose_dynamic(&matrix_d, &rows, &cols);
    puts("After transposing a dynamic matrix:");
    print_dynamic(matrix_d, rows, cols);

    swap_rows_dynamic(matrix_d, rows, 1, 2);
    puts("After swapping rows 1 and 2:");
    print_dynamic(matrix_d, rows, cols);

    swap_cols_dynamic(matrix_d, rows, cols, 1, 2);
    puts("After swapping columns 1 and 2:");
    print_dynamic(matrix_d, rows, cols);
    
    delete_dynamic(matrix_d, ROWS, COLS);
    /*_________________________________________________________________________*/
    
    // Processing (working with) a linear matrix:
    /*_________________________________________________________________________*/
    matrix_l = create_linear(ROWS, COLS);

    init_linear(matrix_l, ROWS, COLS);
    print_linear(matrix_l, ROWS, COLS); 
    
    delete_linear(matrix_l, ROWS, COLS);
    /*_________________________________________________________________________*/

    return 0;
}
