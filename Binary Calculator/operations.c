/* operations.c */
/* Realizations of operations for calculator.c. */
#include <stdio.h>
/* For strchr() */
#include <string.h>
/* For strtol() */
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include "operations.h"

bool analyze_str(const char * math_str, int * left_operand, int * right_operand, 
	char * operation, int * base)
{
	const char * ptr = math_str;
	char * end = NULL;
	bool success = false;
	
	// 0xffffffff
	// Hexadecimal numeric system processing.
	if ('0' == ptr[0] && ('x' == ptr[1] || 'X' == ptr[1]))
	{
		*base = 16;
		*left_operand = my_strtol(ptr + 2, &end, *base);
		// If the *end character is a math operation character.
		if (strchr(BINARY_OPERATIONS, *end))
		{
			*operation = *end;
			ptr = ++end;
			if ('0' == ptr[0] && ('x' == ptr[1] || 'X' == ptr[1]))
			{
				*right_operand = my_strtol(ptr + 2, &end, *base);
			}
		}
	}
	// Octal numeric system processing.
	else if ('0' == ptr[0])
	{
		*base = 8;
		*left_operand = my_strtol(ptr + 1, &end, *base);
		// If the *end character is a math operation character.
		if (strchr(BINARY_OPERATIONS, *end))
		{
			*operation = *end;
			ptr = ++end;
			if ('0' == ptr[0])
			{
				*right_operand = my_strtol(ptr + 1, &end, *base);
			}
		}
	}
	// Binary numeric system processing.
	else if ('1' == ptr[0])
	{
		*base = 2;
		*left_operand = my_strtol(ptr, &end, *base);
		// If the *end character is a math operation character.
		if (strchr(BINARY_OPERATIONS, *end))
		{
			*operation = *end;
			ptr = ++end;
			if ('1' == ptr[0])
			{
				*right_operand = my_strtol(ptr, &end, *base);
			}
		}
	}
	// Invert operation processing (separately).
	else if ('~' == ptr[0])
	{
		*operation = ptr[0];
		// Then hexadecimal operand follows.
		if ('0' == ptr[1] && ('x' == ptr[2] || 'X' == ptr[2]))
		{
			*base = 16;
			*left_operand = my_strtol(ptr + 3, &end, *base);
		}
		// Then octal operand follows.
		else if ('0' == ptr[1])
		{
			*base = 8;
			*left_operand = my_strtol(ptr + 2, &end, *base);
		}
		// Then binary operand follows.
		else if ('1' == ptr[1])
		{
			*base = 2;
			*left_operand = my_strtol(ptr + 1, &end, *base);
		}
		*right_operand = 0;
	}

	if ('\0' == *end)
	{
		success = true;
	}

	return success;
}

long my_strtol(const char * str, char ** endptr, int base) 
{
    int digit = 0;
    int sign = 1;
    long result = 0;
    int i = 0;

    // Skip leading whitespaces.
    while (isspace(str[i]))
    {
        ++i;
    }

    // Check the sign of the number.
    if ('-' == str[i]) 
    {
        sign = -1;
        ++i;
    } 
    else if ('+' == str[i]) 
    {
        ++i;
    }

    // Convert the string into the number.
    while (str[i] != '\0')
    {
        if (isdigit(str[i])) 
        {
            digit = str[i] - '0';
        } 
        else if (isalpha(str[i]))
        {
            if (isupper(str[i])) 
            {
                digit = str[i] - 'A' + 10;
            }
            else 
            {
                digit = str[i] - 'a' + 10;
            }
        } 
        else 
        {
            break;
        }
        if (digit >= base) 
        {
            break;
        }

        result = result * base + digit;
        i++;
    }

    // Set the *endptr to the end part of the string after the conversion.
    *endptr = (char *) &str[i];

    return sign * result;
}

int substrlen(const char * str, int base)
{
	int count = 0;

	while (*str)
	{
		if (2 == base && '1' == *str)
		{

		}
	}
}

int calc_strexpr(int left_operand, int right_operand, char operation)
{
	int result = 0;

	// 1. Invert operation.
	if ('~' == operation)
	{
		result = ~left_operand;
	}
	// Binary operations.
	// 2. Arithmetic operation (5 things).
	else if ('+' == operation)
	{
		result = left_operand + right_operand;
	}
	else if ('-' == operation)
	{
		result = left_operand - right_operand;
	}
	else if ('/' == operation)
	{
		result = left_operand / right_operand;
	}
	else if ('*' == operation)
	{
		result = left_operand * right_operand;
	}
	else if ('%' == operation)
	{
		result = left_operand % right_operand;
	}
	// 3. Bitwise operations.
	else if ('&' == operation)
	{
		result = left_operand & right_operand;
	}
	else if ('|' == operation)
	{
		result = left_operand | right_operand;
	}
	else if ('^' == operation)
	{
		result = left_operand ^ right_operand;
	}
	// Error case.
	else
	{
		result = 0;
	}

	return result;
}

void display(int result, int base, char operation)
{
	printf("Result: ");

	// Output the result in the required numeric system.
	if (2 == base)
	{
		display_binary(result);
	}
	else if (8 == base)
	{
		printf("%#o", result);
	}
	else if (16 == base)
	{
		printf("%#x", result);
	}

	// Ouptut the result in decimal numeric system.
	if (strchr(BITWISE_BIN_OPERATIONS, operation))
	{
		printf(" (%u)\n", result);
	}
	else
	{
		printf(" (%d)\n", result);
	}
}

// Recursive realization of displaying a decimal to binary.
void display_binary(unsigned decimal)
{
	int remainder = decimal % 2;
	if (decimal >= 2)
	{
		display_binary(decimal / 2);
	}
	putchar((remainder) ? '1' : '0');
}

void display_instruct(void)
{
	puts("Enter a math expression in any from these number systems:\n"
		"binary, octal, hexadecimal.");
	puts("The bases of the number systems of the operands must match.");
	puts("Enter an empty line to quit.\n");
}

// String processing functions.
void delete_spaces(char * str)
{
	char * ptr_start = NULL;
	char * ptr_end = NULL;

	while (*str)
	{
		if (!isspace(*str))
		{
			++str;
		}
		else
		{
			// Find the first non-whitespace character in the string.
			ptr_start = ptr_end = str;
			while (isspace(*ptr_end))
			{
				++ptr_end;
			}
			
			// Move the line by the corresponding number of 
			// whitespace characters to the left.
			while (*ptr_end)
			{
				*ptr_start++ = *ptr_end++;
			}
			*ptr_start = '\0';
		}
	}
}

char * s_gets(char * str, int n)
{
	char * ret_val;

	ret_val = fgets(str, n, stdin);
	if (ret_val)
	{
		while (*str && *str != '\n')
		{
			++str;
		}

		if ('\n' == *str)
		{
			*str = '\0';
		}
		else
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}

	return ret_val;
}

// Math functions.
int sum(int a, int b)
{
	return a + b;
}

int subtract(int a, int b)
{
	return a - b;
}

int multiplicate(int a, int b)
{
	return a * b;
}

int divide(int a, int b)
{
	return a / b;
}

int div_module(int a, int b)
{
	return a % b;
}

unsigned binary_and(unsigned a, unsigned b)
{
	return a & b;
}

unsigned binary_or(unsigned a, unsigned b)
{
	return a | b;
}

unsigned binary_xor(unsigned a, unsigned b)
{
	return a ^ b;
}

int binary_invert(int x)
{
	return ~x;
}
