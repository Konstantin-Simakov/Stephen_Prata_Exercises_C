// matrix.h -- header file for matrix_support.c 		 
// Here is supposed 2-dimension array is called matrix.  

#ifndef MATRIX_H_
#define MATRIX_H_

#define ROWS 5						// The number of rows in the allocating matrix 		
#define COLS 6						// The number of columns in the allocating matrix 	

// Function prototypes for a regular matrix:
/*_________________________________________________________________________*/
// Simple functions for a regular matrix:  
void init_regular(int matrix[][COLS], int rows);
void print_regular(int matrix[][COLS], int rows);

// Mathematic operations for a regular matrix:
void swap_rows_regular(int matrix[][COLS], int rows, int row_1, int row_2);
void swap_cols_regular(int matrix[][COLS], int rows, int col_1, int col_2);
/*_________________________________________________________________________*/

// Function prototypes for a dynamic matrix:
/*_________________________________________________________________________*/
// Simple functions for a dynamic matrix creating, processing, freeing:  
int ** create_dynamic(int rows, int cols);
void init_dynamic(int ** matrix, int rows, int cols);
void print_dynamic(int ** matrix, int rows, int cols);
void delete_dynamic(int ** matrix, int rows, int cols);

// Mathematic operations for a dynamic matrix:
void transpose_dynamic(int *** matrix, int * rows, int * cols);
void swap_rows_dynamic(int ** matrix, int rows, int row_1, int row_2);
void swap_cols_dynamic(int ** matrix, int rows, int cols, int col_1, int col_2);
/*_________________________________________________________________________*/

// Function prototypes for a linear matrix:
/*_________________________________________________________________________*/
// Simple functions for a linear matrix creating, processing, freeing:  
int * create_linear(int rows, int cols);
void init_linear(int * matrix, int rows, int cols);
void print_linear(int * matrix, int rows, int cols);
void delete_linear(int * matrix, int rows, int cols);
/*_________________________________________________________________________*/

#endif		// For MATRIX_H_
