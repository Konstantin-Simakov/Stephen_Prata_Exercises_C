/* quest4.c -- Chapter 13 */
#include <stdio.h>
#include <stdlib.h>		// for exit()

#define SIZE 10

double average (double ar[], int n);

int main (int argc, char * argv[])
{
	FILE * fp;
	double temp[SIZE];
	int i = 0;

	if (argc >= 3)
	{
		fputs("Too many arguments for command line.\n"
			"Usage: ./quest4 argv[1] (argv[1] -- is optional)\n", stderr);
		exit(EXIT_FAILURE);
	}
	else if (2 == argc)
	{
		if ((fp = fopen(argv[1], "r")) == NULL) // fp = fopen(argv[1], "r");
		{
			fprintf(stderr, "Couldn't open file %s.\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		while (i < SIZE && fscanf(fp, "%lf", &temp[i]) == 1)
			i++;
		fclose(fp);
	}
	else	// if (1 == argc) <-- it couldn't be less
	{
		puts("Enter any float numbers throuhg space character "
			"(or \'q\' to finish):");
		while (i < SIZE && scanf("%lf", &temp[i]) == 1)
			i++;
	}

	if (i > 0)
		printf("Average is %.2f\n", average(temp, i));
	else
		printf("No valid data available.\n");
	
	return 0;
}

double average (double ar[], int n)
{
	double res;
	int i;

	for (res = 0.0, i = 0; i < n; i++)
		res += ar[i];

	return res / n;
}
