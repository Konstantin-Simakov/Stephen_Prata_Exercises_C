/* exercise9_head.h */
#include <stdbool.h>		/* for bool */

#define LEN 	40
#define SEATS 	12			/* for structure array */
#define FLIGHTS 4 			/* number of flights */
#define HYPHEN 				"------------------------------------------------------------------"

struct name {
	char fname[LEN];
	char lname[LEN];
};

struct seat {
	int number;
	bool book;					/* booked seat - true, otherwise - false */
	bool confirm;				/* confirmation of seat booking (see upper); true - confirm, otherwise - false */
	struct name passenger;
};

void eatline(void);
int showmenu1(void);
char showmenu2(void);
void show_free_num(struct seat aircraft[], int n);
void show_free_list(struct seat aircraft[], int n);
void struct_cpy_arr(struct seat * temp, struct seat * aircraft, int n);
void sort_alph(struct seat arr[], int n);
void show_book_alph(struct seat aircraft[], int n);
void book_seat(struct seat aircraft[], int n);
void confirm_book(struct seat aircraft[], int n);
void cancel_book_seat(struct seat aircraft[], int n);
void output_from_file(struct seat aircraft[], int n, FILE * fp);
void output_to_file(struct seat aircraft[], int n, FILE * fp);
