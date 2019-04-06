// ex14.c -- Chapter 6;
#include <stdio.h>

#define STR_NUM 20

int main (void)
{
	short i;
	char symbols[STR_NUM];

	printf("Enter STR_NUM = 12 characters:\n");

	for (i = 0; i < STR_NUM; i++)
		scanf("%c", &symbols[i]);		// Here we point at value array!; =>
										// => It is necessary to put the sign "&";
	for (i = STR_NUM - 1; i > -1; i--)
		printf("%c", symbols[i]);

	putchar('\n');

	/* Don't forget that \n <==> Enter; */
	
	return 0;
}