// exercise3.c -- Chapter 14
#include <stdio.h>
#include <string.h>				// for strcmp()
#include "exercise3_head.h"		// for template of the structure, etc.

int main (void)
{
	struct book library[BOOKS];
	int stop;

	printf("You should enter no more than %d books.\n", BOOKS);
	puts("(information about them: title, author's name and value of book).");
	stop = init_struct_arr(library, BOOKS);

	printf("%-20sOUTPUT%20s\n", HYPHEN, HYPHEN);
	puts("\nThe output of the contents of the structure in the original order.");
	output_struct_arr(library, stop);

	puts("\nThe output of the contents of the structure in alphabetical order by book title.");
	sort_struct_title(library, stop);
	output_struct_arr(library, stop);

	puts("\nThe output of the contents of the structure in ascending order of book prices.");
	sort_struct_value(library, stop);
	output_struct_arr(library, stop);
	
	return 0;
}
