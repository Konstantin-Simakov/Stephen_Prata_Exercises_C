/* exercise9.c -- Chapter 12 */
#include <stdio.h>		/* for printf(), getchar(), puts(), scanf() */
#include <stdlib.h>		/* for malloc(), free() */

#define SIZE 40

int main (void)
{
	int i;
	int num;
	char * temp;
	char ** words;

	printf("Enter words number: ");
	scanf("%d", &num);
	words = (char **) malloc(num * sizeof(char *));
	
	printf("Now enter %d words:\n", num);
	for (i = 0; i < num; i++)
	{
		temp = (char *) malloc(SIZE * sizeof(char));		
		scanf("%s", temp);
		words[i] = temp;
	}

	puts("Here are words you entered:");
	for (i = 0; i < num; i++)
		puts(words[i]);

	free(words);	// <==> free(temp); for all earlier used temp varables
	
	return 0;
}
