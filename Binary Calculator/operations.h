/* operations.h */
/* Header file for operations.c source file. */

#ifndef OPERATIONS_H_
#define OPERATIONS_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define SIZE 200
#define BINARY_OPERATIONS "+-*/%^|&"
#define BITWISE_BIN_OPERATIONS "&|^"

// Function prototypes.
// String functions.
void delete_spaces(char * str);
char * s_gets(char * str, int n);
long my_strtol(const char * str, char ** endptr, int base);
// Main functions.
bool analyze_str(const char * math_strexpr, int * left_operand, int * right_operand, 
	char * operation, int * base);
int calc_strexpr(int left_operand, int right_operand, char operation);
void display_instruct(void);
void display_binary(unsigned decimal);
void display(int result, int base, char operation);

#endif	/* OPERATIONS_H_ */
