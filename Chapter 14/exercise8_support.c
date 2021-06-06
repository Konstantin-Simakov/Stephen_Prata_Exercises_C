/* exercise8_support.c */
#include <stdio.h>
#include <string.h>				/* for strcmp() */
#include <ctype.h>				/* for tolower() */
#include "exercise8_head.h"

void eatline (void)
{
	while (getchar() != '\n')
		continue;
}

char showmenu (void)
{
	char ans;

	puts("\nTo select a function, enter its letter label:");
	puts("a) Show the number of free seats");
	puts("b) Show the list of free seats");
	puts("c) Show the list of booked seats in alphabetical order");
	puts("d) Book a seat for a passenger");
	puts("e) Remove the book from the seat");
	puts("f) Exit the program");
	ans = tolower(getchar());
	eatline();
	while (strchr("abcdef", ans) == NULL)
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
			printf("Seat: %2d, passenger:  %-6s %-1s\n", 
				temp[i].number, temp[i].passenger.fname, temp[i].passenger.lname);
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

void cancel_book_seat (struct seat aircraft[], int n)
{
	int num;		/* the number of desired (cancel booked) seat */

	puts("What seat do you want to cancel book?");
	puts("(q to exit to menu)");
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

	while (i < n && fread(&aircraft[i], sizeof(struct seat), 1, fp) == 1)
	{
		if (0 == i)
		{
			puts("\nInformation about the seats on the aircraft:");
			printf("%-10s %-15s %-15s %-10s\n", "N(place)", "Book", "L.name", "F.name");
			puts(HYPHEN);
		}
		printf("%-10d %-15s %-15s %-10s\n", 
			aircraft[i].number, aircraft[i].book ? "booked" : "canceled", 
			aircraft[i].passenger.lname, aircraft[i].passenger.fname);
		i++;
	}
}

void output_to_file (struct seat aircraft[], int n, FILE * fp)
{
	int i;

	puts("\nThe aircraft content (end):");
	printf("%-10s %-15s %-15s %-10s\n", "N(place)", "Book", "L.name", "F.name");
	puts(HYPHEN);
	for (i = 0; i < n; i++)
	{
		printf("%-10d %-15s %-15s %-10s\n", 
			aircraft[i].number, aircraft[i].book ? "booked" : "canceled", 
			aircraft[i].passenger.lname, aircraft[i].passenger.fname);
	}

	fwrite(aircraft, sizeof(struct seat), n, fp);
}
