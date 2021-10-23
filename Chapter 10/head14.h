/* head14.h -- 	header file for exercise14.c;
				processing arrays by using arrays of variable length; */
#define ROWS 3
#define COLS 5

/* no const for this function only because it changes a source array */
void input(int rows, int cols, double ar[rows][cols]);

double average(int n, const double ar[n]);
double average_all(int rows, int cols, const double ar[rows][cols]);
double biggest(int rows, int cols, const double ar[rows][cols]);

/* three times (double *) is used 
for (double; return values for every function above) */
void show_results(int rows, int cols, const double ar[rows][cols]);