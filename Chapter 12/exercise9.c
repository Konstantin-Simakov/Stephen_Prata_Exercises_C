/* exercise9.c -- Chapter 12 */
#include <stdio.h>		/* for printf(), getchar(), puts(), scanf()	 */
#include <stdlib.h>		/* for malloc(), free() 			 */
#include <string.h>		/* for strlen(), strcpy()			 */

#define SIZE 40

int main(void)
{
	int i;
	int num;
	char temp[SIZE];
	char * word;
	char ** words;

	printf("Enter words number: ");
	scanf("%d", &num);
	words = (char **) malloc(num * sizeof(char *));		/* ??? */

	printf("Now enter these %d words:\n", num);
	for (i = 0; i < num; i++)
	{
		scanf("%s", temp);
		word = (char *) malloc((strlen(temp) + 1) * sizeof(char));
		strcpy(word, temp);		
		words[i] = word;
	}

	printf("Here are all %d words you entered:\n", num);
	for (i = 0; i < num; i++)
		puts(words[i]);

	free(words);	/* <==> free(word); for all previously created 	*/
			/* 	dynamic char arrays named word		*/

	return 0;
}
