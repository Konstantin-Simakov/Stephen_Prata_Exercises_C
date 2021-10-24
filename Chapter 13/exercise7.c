/* exercise7.c -- part a -- Chapter 13 */
#include <stdio.h>
#include <stdlib.h>		// for exit()

#define LEN 20

char * s_gets(char *, int);
void output_str_to_str(FILE * fp1, FILE * fp2);

int main(void)
{
	FILE * fp1, * fp2;
	char fname1_str[LEN], fname2_str[LEN];

	// Preparation for the implementing part of the code.
	// It is opening the required files.
	////////////////////////////////////////////////////////////////////////////////////////
	// It is opening the first file.
	puts("Enter the first file name:");
	s_gets(fname1_str, LEN);
	if ((fp1 = fopen(fname1_str, "r")) == NULL)
	{
		fprintf(stderr, "Cannot find file \"%s\" in this catalog.\n", fname1_str);
		exit(EXIT_FAILURE);
	}

	// It is opening the second file.
	puts("Enter the second file name:");
	s_gets(fname2_str, LEN);
	if ((fp2 = fopen(fname2_str, "r")) == NULL)
	{
		fprintf(stderr, "Cannot find file \"%s\" in this catalog.\n", fname2_str);
		exit(EXIT_FAILURE);
	}
	////////////////////////////////////////////////////////////////////////////////////////

	// It is code realization.
	output_str_to_str(fp1, fp2);
	
	// Closing the corresponding data streams (closing the corresponding opened files).
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}

char * s_gets(char * str, int n)
{
	char * ret_val;

	ret_val = fgets(str, n, stdin);

	if (ret_val != NULL)
	{
		while (*str != '\n' && *str != '\0')
			str++;

		if ('\n' == *str)
			*str = '\0';
		else	// if ('\0' == *str)
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}

void output_str_to_str(FILE * fp1, FILE * fp2)
{
	// An array of sufficient size for the string is required 
	// to ensure that a newline character is read. (See the code below.)
	const int STLEN = 100;

	char temp1_str[STLEN], temp2_str[STLEN];
	char * ret_val1, * ret_val2;

	while ((ret_val1 = fgets(temp1_str, STLEN, fp1)) && (ret_val2 = fgets(temp2_str, STLEN, fp2)))
	{
		fputs(temp1_str, stdout);
		fputs(temp2_str, stdout);
	}

	// Since the position indicator in the file, where the EOF is not reached, 
	// does not change (only when using the rewind () function), the input and output, 
	// respectively, continue from the moment where they ended in the previous cycle. 
	// (See the code below.)
	if (ret_val1)
		while (fgets(temp1_str, STLEN, fp1))
			fputs(temp1_str, stdout);
	else // if (ret_val2) == if (!ret_val1)
		while (fgets(temp2_str, STLEN, fp2))	// while fgets() doesn't meet EOF
			fputs(temp2_str, stdout);
}
