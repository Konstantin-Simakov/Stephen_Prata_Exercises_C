/* exercise7_support.c */
/* compile with exercise7.c */
#include "exercise7_head.h"
#include <stdio.h>
#include <stdbool.h>		/* for bool, true, false */
#include <ctype.h>			/* for tolower() */
#include <string.h>			/* for strchr() */

void eatline (void)
{
	while (getchar() != '\n')
		continue;
}

char show_menu (void)
{
	int ans;

	putchar('\n');
	puts("f) change font    s) change size    a) align");
	puts("b) bold           i) italic         u) underline");
	puts("q) quit");
	ans = tolower(getchar());
	eatline();
	while (strchr("qfsabiu", ans) == NULL)
	{
		puts("Incorrect letter was entered. Try again:");
		ans = tolower(getchar());
		eatline();
	}

	return ans;
}

/* It is assumed that all bits are preset to zero before using init(). */
unsigned init (unsigned text)
{
	text |= 1;
	text |= 12 * MULT_SIZE;		/* == 0xC00 */
	text |= 0 * MULT_ALIGN;
	text |= false * MULT_BOLD;
	text |= false * MULT_ITALIC;
	text |= false * MULT_UNDER;

	return text;
}

unsigned font_id_change (unsigned text)
{
	int temp;

	printf("Enter the identifier of the font (integer 0-255): ");
	while (scanf("%d", &temp) != 1)
	{
		eatline();
		printf("Non-digit character was entered. Try again: ");
	}
	eatline();

	if (temp >= 0 && temp <= MAX1)
	{
		text &= ~MASK_ID;
		text |= temp;
	}
	else
		puts("Invalid range. Source value won't be changed.");

	return text;
}

unsigned size_change (unsigned text)
{
	int temp;

	printf("Enter the size of the font (integer 0-127): ");
	while (scanf("%d", &temp) != 1)
	{
		eatline();
		printf("Non-digit character was entered. Try again: ");
	}
	eatline();

	if (temp >= 0 && temp <= MAX2)
	{
		text &= ~MASK_SIZE;
		text |= temp * MULT_SIZE;
	}
	else
		puts("Invalid range. Source value won't be changed.");

	return text;
}

unsigned align_change (unsigned text)
{
	char ans;

	ans = show_menu_2();
	switch (ans)
	{
		case 'l': text &= ~MASK_ALIGN;
				text |= 0 * MULT_ALIGN;
				break;
		case 'c': text &= ~MASK_ALIGN;
				text |= 1 * MULT_ALIGN;
				break;
		case 'r': text &= ~MASK_ALIGN;
				text |= 2 * MULT_ALIGN;
				break;
		default : puts("Error 2");
	}

	return text;
}

char show_menu_2 (void)
{
	int ans;

	puts("Choose the align:");
	puts("l) left\t\t c) center\t\t r) right");

	ans = tolower(getchar());
	eatline();
	while (strchr("lcr", ans) == NULL)
	{
		puts("Incorrect letter was entered. Try again:");
		ans = tolower(getchar());
		eatline();
	}

	return ans;
}

unsigned bold (unsigned text)
{
	if (text & MASK_BOLD)
	{
		text &= ~MASK_BOLD;
		text |= false * MULT_BOLD;
	}
	else
	{
		text &= ~MASK_BOLD;
		text |= true * MULT_BOLD;
	}

	return text;
}

unsigned italic (unsigned text)
{
	if (text & MASK_ITALIC)
	{
		text &= ~MASK_ITALIC;
		text |= false * MULT_ITALIC;
	}
	else
	{
		text &= ~MASK_ITALIC;
		text |= true * MULT_ITALIC;
	}

	return text;
}

unsigned underline (unsigned text)
{
	if (text & MASK_UNDER)
	{
		text &= ~MASK_UNDER;
		text |= false * MULT_UNDER;
	}
	else
	{
		text &= ~MASK_UNDER;
		text |= true * MULT_UNDER;
	}

	return text;
}

void output (const unsigned text)
{
	char * str;
	int temp = (text >> 16) & 0x3;		/* 0x3 == 11 (binary) */

	if (0 == temp)
		str = "left";
	else if (1 == temp)
		str = "center";
	else
		str = "right";

	putchar('\n');
	printf("%-8s %-8s %-8s %-8s %-8s %-8s\n", "ID", "SIZE", "ALIGN", "Bold", "Italic", "Underline");
	printf("%-8u %-8u %-8s %-8s %-8s %-8s\n", text & 0xFF, text >> 8 & 0x7F, 
		str, text >> 18 & 0x1 ? "on" : "off", text >> 19 & 0x1 ? "on" : "off", text >> 20 & 0x1 ? "on" : "off");
}
