/* quest5.c -- Chapter 13 */
#include <stdio.h>
#include <stdlib.h>		// for exit()
#include <string.h>		// for strlen(), strchr()

#define SIZE (256 + 1)	// By the statement of the problem, none of the lines should exceed 256 bytes.

int main(int argc, char * argv[])
{
	FILE * fp;			// for argv[2]
	char temp[SIZE];
	int ct_str = 0;		// the numbers of 

	if (argc > 3)
	{
		fputs("Too many arguments.\n"
			"Usage:\n""./quest5 argv[1] argv[2]\n", stderr);
		exit(EXIT_FAILURE);
	}
	else if (argc < 3)
	{
		fputs("Too few arguments.\n"
			"Usage:\n""./quest5 argv[1] argv[2]\n", stderr);
		exit(EXIT_FAILURE);
	}

	// else if all is good...
	if (strlen(argv[1]) > 1)
	{
		fputs("argv[1] must have 1 character.\n", stderr);
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((fp = fopen(argv[2], "r")) == NULL)
		{
			fprintf(stderr, "There is no \"%s\" file in this directory.\n", argv[2]);
			exit(EXIT_FAILURE);
		}

		while (fgets(temp, SIZE, fp) != NULL)
			if (strchr(temp, argv[1][0]))		// search for argv[1][0] character in the temp string array
			{
				fputs(temp, stdout);			// because there is used fgets()
				ct_str++;
			}
		if (0 == ct_str)
			printf("This file doesn't consist character \'%c\'\n", argv[1][0]);
			
		fclose(fp);
	}
	
	return 0;
}
