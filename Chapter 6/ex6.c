// ex6.c -- chapter 6;
#include <stdio.h>
#include <string.h>

#define NEG_MIN_LIM -1
#define SIZE 100

int main (void)
{
	char word[SIZE];
	int i;

	printf("Please, enter your word.\n");
	scanf("%s", word);	  // that's TRUE.

	for (i = strlen(word) - 1; i > NEG_MIN_LIM; i--)
		printf("%c", word[i]);

/*	i = strlen(word);
	printf("\ni = %d", i);
*/	printf("\n");

	
	return 0;
}