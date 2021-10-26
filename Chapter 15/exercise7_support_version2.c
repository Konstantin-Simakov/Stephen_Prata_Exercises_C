/* exercise7_support_version2.c */
/* compile with exercise7_version2.c */
#include "exercise7_head_version2.h"
#include <stdio.h>
#include <stdbool.h>		/* for bool, true, false */
#include <ctype.h>			/* for tolower() */
#include <string.h>			/* for strchr() */

void eatline(void)
{
	while (getchar() != '\n')
		continue;
}

char show_menu(void)
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
unsigned init(unsigned text)
{
	text |= 1 * (0x1 << MULT_ID);
	text |= 12 * (0x1 << MULT_SIZE);		/* == 0xC00 */
	text |= 0 * (0x1 << MULT_ALIGN);
	text |= false * (0x1 << MULT_BOLD);
	text |= false * (0x1 << MULT_ITALIC);
	text |= false * (0x1 << MULT_UNDER);

	return text;
}

unsigned font_id_change(unsigned text)
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
		text |= temp * (0x1 << MULT_ID);
	}
	else
		puts("Invalid range. Source value won't be changed.");

	return text;
}

unsigned size_change(unsigned text)
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
		text |= temp * (0x1 << MULT_SIZE);
	}
	else
		puts("Invalid range. Source value won't be changed.");

	return text;
}

unsigned align_change(unsigned text)
{
	char ans;

	ans = show_menu_2();
	switch (ans)
	{
		case 'l': text &= ~MASK_ALIGN;
				text |= 0 * (0x1 << MULT_ALIGN);
				break;
		case 'c': text &= ~MASK_ALIGN;
				text |= 1 * (0x1 << MULT_ALIGN);
				break;
		case 'r': text &= ~MASK_ALIGN;
				text |= 2 * (0x1 << MULT_ALIGN);
				break;
		default : puts("Error 2");
	}

	return text;
}

char show_menu_2(void)
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

unsigned bold(unsigned text)
{
	if (text & MASK_BOLD)
	{
		text &= ~MASK_BOLD;
		text |= false * (0x1 << MULT_BOLD);
	}
	else
	{
		text &= ~MASK_BOLD;
		text |= true * (0x1 << MULT_BOLD);			/* it is assumed that true == 1 */
	}

	return text;
}

unsigned italic(unsigned text)
{
	if (text & MASK_ITALIC)
	{
		text &= ~MASK_ITALIC;
		text |= false * (0x1 << MULT_ITALIC);
	}
	else
	{
		text &= ~MASK_ITALIC;
		text |= true * (0x1 << MULT_ITALIC);
	}

	return text;
}

unsigned underline(unsigned text)
{
	if (text & MASK_UNDER)
	{
		text &= ~MASK_UNDER;
		text |= false * (0x1 << MULT_UNDER);
	}
	else
	{
		text &= ~MASK_UNDER;
		text |= true * (0x1 << MULT_UNDER);
	}

	return text;
}

void output(const unsigned text)
{
	char * str;
	int temp = (text >> MULT_ALIGN) & 0x3;		/* 0x3 == 11 (binary; it is mask) */

	if (0 == temp)
		str = "left";
	else if (1 == temp)
		str = "center";
	else
		str = "right";

	putchar('\n');
	printf("%-8s %-8s %-8s %-8s %-8s %-8s\n", "ID", "SIZE", "ALIGN", "Bold", "Italic", "Underline");
	printf("%-8u %-8u %-8s %-8s %-8s %-8s\n", text >> MULT_ID & MAX1, text >> MULT_SIZE & MAX2, str, 	/* note: MAX1 > MAX2 */
		text >> MULT_BOLD & 0x1 ? "on" : "off", text >> MULT_ITALIC & 0x1 ? "on" : "off", text >> MULT_UNDER & 0x1 ? "on" : "off");
}
