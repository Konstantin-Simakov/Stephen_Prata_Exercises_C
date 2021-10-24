/* exercise14_vers2.c -- Chapter 11 */
#include <stdio.h>
#include <stdlib.h>		// for strtod() -- double, strtol() -- long

double power(double base, long exponent);		// long is for strtol()

int main(int argc, char ** argv)
{
	double base;		// for double -- strtod()
	long n;				// for long -- strtol()
	char * base_end;
	char * n_end;

	if (argc < 3)
		printf("Application: %s double-number integer-positive-number\n", argv[0]);
	else
	{
		base = strtod(argv[1], &base_end);
		n = strtol(argv[2], &n_end, 10);
		printf("Number: base = %.2f, stopped at %s (%d), exponent = %ld, stopped at %s (%d).\n", 
								base, 	 base_end,  *base_end, 		   n, 		 n_end, *n_end);
		printf("The power of this number is %.2f\n", power(base, n));
	}

	return 0;
}

/* for positive exponent only (for now...) */
double power(double base, long n)
{
	long i;
	double res;

	if (n < 0)
	{
		n = -n;
		for (i = 1, res = 1; i <= n; i++)
			res *= base;
		res = 1 / res;
	}
	else if (n > 0)
		for (i = 1, res = 1; i <= n; i++)
			res *= base;
	else if (base != 0)
			res = 1;
	else	// else if (0 == base)
	{
		printf("Result undefined.\n");
		res = 1;
	}


	return res;
}
