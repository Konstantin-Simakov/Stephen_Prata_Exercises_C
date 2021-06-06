/* exercise8.c -- Chapter 14 */
#include <stdio.h>
#include <stdlib.h>			/* for exit() */
#include "exercise8_head.h"

int main (void)
{
	struct seat aircraft[SEATS] = {
		{ 1, 	true, 	{"Ivan", 	"Ivanov"} 		}, 
		{ 2, 	true, 	{"Oleg", 	"Olegov"} 		}, 
		{ 3, 	false, 	{"Sidor", 	"Sidorov"} 		}, 
		{ 4, 	true, 	{"Maria", 	"Lazarina"} 	}, 
		{ 5, 	false, 	{"Prokofy", "Prokofiev"} 	}, 
		{ 6, 	true, 	{"Trand", 	"Trandov"} 		}, 
		{ 7, 	false, 	{"Chris", 	"Christov"} 	}, 
		{ 8, 	true, 	{"Tuvat", 	"Tuvatin"} 		}, 
		{ 9, 	false, 	{"Orel", 	"Orlov"} 		}, 
		{ 10, 	true, 	{"Bell", 	"Belov"} 		}, 
		{ 11, 	true, 	{"Red", 	"Redkov"} 		}, 
		{ 12, 	false, 	{"Sav", 	"Savostyanov"} 	}, 
	};
	char choice;
	FILE * fp;

	if ((fp = fopen("aircraft.dat", "r+b")) == NULL)			/* correct mode (good)! */
	{
		fputs("There is no \"aircraft.dat\" file in this directory.\n", stderr);
		exit(EXIT_FAILURE);
	}

	output_from_file(aircraft, SEATS, fp);

	while ((choice = showmenu()) != 'f')
		switch (choice)
		{
			case 'a': show_free_num(aircraft, SEATS);
				break;
			case 'b': show_free_list(aircraft, SEATS);
				break;
			case 'c': show_book_alph(aircraft, SEATS);
				break;
			case 'd': book_seat(aircraft, SEATS);
				break;
			case 'e': cancel_book_seat(aircraft, SEATS);
				break;
			default : puts("Error 1");
		}

	rewind(fp);
	output_to_file(aircraft, SEATS, fp);
	fclose(fp);
	puts("\nThe program has been completed.");
	
	return 0;
}
