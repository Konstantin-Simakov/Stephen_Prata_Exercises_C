/* exercise13.c -- Chapter 11 */
#include <stdio.h>

int main (int argc, char ** argv)
{
	int i;

	printf("\t   ");
	for (i = argc - 1; i >= 1; i--)		// without the program name because i >= 1
		printf("%s ", argv[i]);
	putchar('\n');
	
	return 0;
}
