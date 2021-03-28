/* head5.h -- Chapter 12 */
/* this header file -- for exercise5.c (and suppoert5.c if it is necessary) */

#define SIZE 100		// number of elements in the list of numbers sorted decsending

/* this function (init_ar_rand()) must be use only after srand() in the main() */
void init_ar_rand (int [], int);		// <=> (int *, int)
void sort_decsend_nums (int [], int);
void output_ar_line (int [], int);
