/* exercise5.c -- Chapter 15 */
#include <stdio.h>
#include <stdlib.h>		/* for exit(), EXIT_FAILURE */
#include <limits.h>		/* for CHAR_BIT */
#include <string.h>
#include <math.h>		/* add "-lm" option to compile */

/* + 1 -- for '\0' character in the end of the string */
const static int STLEN = CHAR_BIT * sizeof(short);			/* STLEN -- without '\0' character */

unsigned rotate_left (unsigned num, int n_pos);
char * itobs (int num, char * str, int n);
int bstoi (char * str);

int main (void)
{
	unsigned x = 15;
	char str[STLEN + 1];		
	char * temp; 

	temp = itobs(x, str, STLEN + 1);
	printf("source value of x = %4d, x = %33s\n", x, temp);

	temp = itobs(rotate_left(x, 4), str, STLEN + 1);
	printf("rotate_left(%d, 4) = %d, rotate_left(%d, 4) = %s\n", x, rotate_left(x, 4), x, temp);
	printf("rotate_left(%d, 4) = %d\n", x, bstoi(temp));
	
	return 0;
}

unsigned rotate_left (unsigned num, int n_pos)
{
	const int MAX_POS = STLEN - 1;		/* (- 1) -- '\0'; (- 1) -- index, not a counter */
										/* => (- 2) => (STLEN - 2) */
	unsigned temp;
	int i;

	if (n_pos < 0 || n_pos > MAX_POS)
	{
		puts("Invalid position was entered.");
		puts("The program has been completed.");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < n_pos; i++)			/* n_pos is a number of shifted positions, not position index */
	{
		temp = (num >> MAX_POS) & 0x1;
		num <<= 1;
		num |= temp;
	}

	return num;
}

char * itobs (int num, char * str, int n)
{
	int i;

	for (i = n - 2; i >= 0; i--, num >>= 1)
		str[i] = (num & 0x1) + '0';
	str[n - 1] = '\0';

	return str;
}

int bstoi (char * str)
{
	const int MAX_POWER = strlen(str) - 1;
	
	int i;
	int res;

	for (res = 0, i = 0; i <= MAX_POWER; i++)
	{
		if ('1' == str[i])
			res += pow(2, MAX_POWER - i);
	}

	return res;
}
