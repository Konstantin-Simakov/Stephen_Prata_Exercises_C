/* exercise2.c -- Chapter 13 */
#include <stdio.h>
#include <stdlib.h>		// for exit()

int main (int argc, char * argv[])
{
	FILE * fp_src, * fp_trg;
	int ch;

	if (argc != 3)
	{
		puts("Invalid number of arguments.");
		puts("Usage:");
		printf("%s <filename_src> <filename_trg>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	if ((fp_src = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "Cannot open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((fp_trg = fopen(argv[2], "wb")) == NULL)
	{
		fprintf(stderr, "Cannot open file %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fp_src)) != EOF)
		putc(ch, fp_trg);

	fclose(fp_src);
	fclose(fp_trg);

	puts("The program has been completed.");
	
	return 0;
}
