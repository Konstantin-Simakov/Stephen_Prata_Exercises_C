/* head13.h -- header file for exercise13.c */
#define ROWS 3
#define COLS 5

/* no const for this function only because it changes a source array */
void input(double ar[][COLS], int rows);

double average(const double ar[], int n);
double average_all(const double ar[][COLS], int rows);
double biggest(const double ar[][COLS], int rows);

/* three times (double *) is used 
for (double; return values for every function above) */
void show_results(const double ar[][COLS], int rows);