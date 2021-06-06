/* exercise9_support.c */
#include <stdio.h>
#include <string.h>				/* for strcmp() */
#include <ctype.h>				/* for tolower() */
#include "exercise9_head.h"

void eatline (void)
{
	while (getchar() != '\n')
		continue;
}

int showmenu1 (void)
{
	int res;

	puts("\nEnter the number of flight: 102, 311, 444 or 519.");
	puts("(or 0 to exit the program)");
	while (scanf("%d", &res) != 1 
		|| (res != 102 && res != 311 && res != 444 && res != 519 && res != 0))
	{
		eatline();
		puts("Incorrect number has been entered. Try again:");
		puts("(Valid values for input: 102, 311, 444, 519, 0.");
	}
	eatline();

	return res;
}

char showmenu2 (void)
{
	char ans;

	puts("\nTo select a function, enter its letter label:");
	puts("a) Show the number of free seats");
	puts("b) Show the list of free seats");
	puts("c) Show the list of booked seats in alphabetical order");
	puts("d) Book a seat for a passenger");
	puts("e) Confirm a booking");
	puts("f) Remove the book from the seat");
	puts("g) Return to the menu level up");
	ans = tolower(getchar());
	eatline();
	while (strchr("abcdefg", ans) == NULL)
	{
		puts("Incorrect letter has been entered. Try again:");
		ans = tolower(getchar());
		eatline();
	}

	return ans;
}

/* p. a) */
void show_free_num (struct seat aircraft[], int n)
{
	int i, sum;

	for (sum = 0, i = 0; i < n; i++)
		if (!aircraft[i].book)
			sum++;

	printf("The number of free seats is %d.\n", sum);
}

/* p. b) */
void show_free_list (struct seat aircraft[], int n)
{
	int i;

	printf("The next numbers of seats are free: ");
	for (i = 0; i < n; i++)
		if (!aircraft[i].book)
			printf("%d, ", aircraft[i].number);
	printf("\b\b.\n");
}

void struct_cpy_arr (struct seat * temp, struct seat * aircraft, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		temp[i].number = aircraft[i].number;
		temp[i].book = aircraft[i].book;
		strcpy(temp[i].passenger.fname, aircraft[i].passenger.fname);
		strcpy(temp[i].passenger.lname, aircraft[i].passenger.lname);
	}
}

void sort_alph (struct seat arr[], int n)
{
	int top, seek;
	struct seat temp;

	for (top = 0; top < n - 1; top++)
		for (seek = top + 1; seek < n; seek++)
			if (strcmp(arr[top].passenger.lname, arr[seek].passenger.lname) > 0)
			{
				temp = arr[top];
				arr[top] = arr[seek];
				arr[seek] = temp;
			}
}

void show_book_alph (struct seat aircraft[], int n)
{
	int i;
	struct seat temp[n];

	struct_cpy_arr(temp, aircraft, n);
	sort_alph(temp, n);

	puts("The list of booked seats in alphabetical order:");
	for (i = 0; i < n; i++)
		if (temp[i].book)
			printf("Seat: %2d, booking confirm: %3s, passenger:  %-6s %-1s\n", 
				temp[i].number, (temp[i].confirm) ? "yes" : "no", 
				temp[i].passenger.fname, temp[i].passenger.lname);
}

void book_seat (struct seat aircraft[], int n)
{
	int num;		/* the number of desired (booked) seat */

	puts("What seat do you want to book?");
	puts("(q to exit to menu)");
	while (scanf("%d", &num) == 1)
	{
		if (num >= 1 && num <= n)
		{
			if (!aircraft[num - 1].book)
			{
				aircraft[num - 1].book = true;
				aircraft[num - 1].confirm = false;
				puts("Successfully (true).");
				puts("What seat do you want to book yet?");
			}
			else
				puts("This place has been booked already.");
		}
		else
			puts("Invalid range.");
	}
	eatline();
}

void confirm_book (struct seat aircraft[], int n)
{
	int num;

	puts("What booking seat do you want to confirm?");
	puts("(q to exit to menu level up)");
	while (scanf("%d", &num) == 1)
	{
		if (num >= 1 && num <= n)
		{
			if (aircraft[num - 1].book)
			{
				if (!aircraft[num - 1].confirm)
				{
					aircraft[num - 1].confirm = true;
					puts("Successfully confirm (true).");

					puts("What booking seat do you want to confirm yet?");					
				}
				else
					puts("This place has been confirmed already.");
			}
			else
				puts("This place hasn't been booked. Cannot confirm booking.");
		}
		else
			puts("Invalid range.");
	}
	eatline();
}

void cancel_book_seat (struct seat aircraft[], int n)
{
	int num;		/* the number of desired (cancel booked) seat */

	puts("What seat do you want to cancel book?");
	puts("(q to exit to menu level up)");
	while (scanf("%d", &num) == 1)
	{
		if (num >= 1 && num <= n)
		{
			if (aircraft[num - 1].book)
			{
				aircraft[num - 1].book = false;
				puts("Successfully canceled (false).");

				puts("What seat do you want to cancel book yet?");
			}
			else
				puts("This place has been canceled book already.");
		}
		else
			puts("Invalid range.");
	}
	eatline();
}

void output_from_file (struct seat aircraft[], int n, FILE * fp)
{
	int i = 0;
	char * pstr;

	while (i < n && fread(&aircraft[i], sizeof(struct seat), 1, fp) == 1)
	{
		if (0 == i)
		{
			puts("Information about the seats on the aircraft:");
			printf("%-10s %-15s %-15s %-15s %-10s\n", "N(place)", "Book", "Confirm", "L.name", "F.name");
			puts(HYPHEN);
		}

		if (aircraft[i].book)
		{
			if (aircraft[i].confirm)
				pstr = "confirm";
			else
				pstr = "no";
		}
		else
			pstr = "---";

		printf("%-10d %-15s %-15s %-15s %-10s\n", 
			aircraft[i].number, (aircraft[i].book) ? "booked" : "canceled", 		/* 2 arguments */
			pstr, aircraft[i].passenger.lname, aircraft[i].passenger.fname);		/* 3 arguments */

		i++;
	}
}

void output_to_file (struct seat aircraft[], int n, FILE * fp)
{
	const char * pstr;
	int i;

	puts("The aircraft content (end):");
	printf("%-10s %-15s %-15s %-15s %-10s\n", "N(place)", "Book", "Confirm", "L.name", "F.name");
	puts(HYPHEN);
	for (i = 0; i < n; i++)
	{
		if (aircraft[i].book)
		{
			if (aircraft[i].confirm)
				pstr = "confirm";
			else
				pstr = "no";
		}
		else
			pstr = "---";

		printf("%-10d %-15s %-15s %-15s %-10s\n", 
			aircraft[i].number, (aircraft[i].book) ? "booked" : "canceled", 		/* 2 arguments */
			pstr, aircraft[i].passenger.lname, aircraft[i].passenger.fname);		/* 3 arguments */
	}

	fwrite(aircraft, sizeof(struct seat), n, fp);
}
