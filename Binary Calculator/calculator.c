/* calculator.c */
/* Calculator for binary, octal and hexadecimal numeric system 
(for a while only for integers). */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "operations.h"

int main(void)
{
	char math_str[SIZE];
	int left_operand, right_operand;
	char operation;
	int base;
	int result;

	display_instruct();
	puts("\nEnter a math expression.");
	while (s_gets(math_str, SIZE) && math_str[0])
	{
		delete_spaces(math_str);
		if (!analyze_str(math_str, &left_operand, &right_operand, &operation, &base))
		{
			puts("Incorrect data input.");
			exit(EXIT_FAILURE);
		}
		result = calc_strexpr(left_operand, right_operand, operation);
		display(result, base, operation);
		
		puts("\nEnter a next math expression.");
	}
	puts("\nBye!");

	return 0;
}

