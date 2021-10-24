/* exercise11.c -- Chapter 13 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>		// for strstr()

#define MAXL 101

int main(int argc, char * argv[])
{
	FILE * fp;
	char fstring[MAXL];

	// It is incorrect arguments number processing.
	if (argc != 3)
	{
		fprintf(stderr, "Incorrect arguments number!\n"
			"Usage:\n"
			"%s <string> <file name>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[2], "r")) == NULL)
	{
		fprintf(stderr, "Cannot find file %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while (fgets(fstring, MAXL, fp))
		if (strstr(fstring, argv[1]) != NULL)		// If the target string argv[1] is found in the source string,
			fputs(fstring, stdout);					// output the source string.
	
	return 0;
}
