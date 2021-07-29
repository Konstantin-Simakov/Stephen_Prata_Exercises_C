/* exercise7.c -- Chapter 16 */
#include <stdio.h>
#include <stdlib.h>		/* for malloc(), free() */
#include <stdarg.h>		/* for a function with a variable number of arguments */

void show_array (const double ar[], int n);
double * new_d_array (int n, ...);

int main (void)
{
	double * p1;
	double * p2;

	p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
	p2 = new_d_array(4, 100.0, 20.0, 8.08, -1890.0);

	show_array(p1, 5);
	show_array(p2, 4);

	free(p1);
	free(p2);

	return 0;
}

double * new_d_array (int n, ...)
{
	va_list arg_ptr;
	int i;
	double * d_ptr = (double *) malloc(n * sizeof(double));

	va_start(arg_ptr, n);
	for (i = 0; i < n; i++)
		d_ptr[i] = va_arg(arg_ptr, double);
	va_end(arg_ptr);					/* try to comment this line and compile again... 
												...What's going to happen? */
	return d_ptr;
}

void show_array (const double ar[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%10.2f ", ar[i]);
	putchar('\n');
}
