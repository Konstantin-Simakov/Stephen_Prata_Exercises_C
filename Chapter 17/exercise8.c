/* exercise8.c -- Chapter 17 						*/
/* 				  compile with exercise8_support.c 	*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "exercise8.h"

/* user (global) function prototypes 				*/
void eatline(void);
char menu(void);
void add_pet(Tree * ptree);
void drop_pet(Tree * ptree);
void show_pets(const Tree * ptree);
void find_pet(const Tree * ptree);
void print_item(Item output);
void upper_case(char * str);
char * s_gets(char * str, int n);

/* local (static) function prototypes 				*/
static void output_pets(const Trnode * pnode);

int main(void)
{
	Tree pets;
	char choice;

	initialize_tree(&pets);
	while ((choice = menu()) != 'q')
	{
		switch (choice)
		{
			case 'a': add_pet(&pets);
				break;
			case 'l': show_pets(&pets);
				break;
			case 'f': find_pet(&pets);
				break;
			case 'n': printf("%d animals in the club.\n", 
						tree_item_count(&pets));
				break;
			case 'd': drop_pet(&pets);
				break;
			default : puts("switch error");
		}
	}
	delete_all(&pets);
	puts("The program has been completed.");
	
	return 0;
}

void eatline(void)
{
	while (getchar() != '\n')
		continue;
}

char menu(void)
{
	int ch;

	puts("Nerfville Pet Club Membership Program");
	puts("Enter the letter corresponding to your choice:");
	puts("a) adding animal        l) list animals");
	puts("n) number of animals    f) find animals");
	puts("d) deleting animal      q) quit");
	while ((ch = getchar()) != EOF)
	{
		eatline();
		ch = tolower(ch);
		if (strchr("alnfdq", ch) == NULL)
			puts("Enter the letter: a, l, f, n, d or q.");
		else
			break;
	}
	if (EOF == ch)
		ch = 'q';

	return ch;
}

void add_pet(Tree * ptree)
{
	Item temp;

	if (tree_is_full(ptree))
		puts("There are no more seats in the club!");
	else
	{
		puts("Enter the pet name:");
		s_gets(temp.petname, STLEN);
		puts("Enter the pet kind:");
		s_gets(temp.petkind, STLEN);

		upper_case(temp.petname);
		upper_case(temp.petkind);

		if (add_item(ptree, &temp))
			printf("The pet %s named %s includes successfully!\n", 
				temp.petkind, temp.petname);
		else
			fputs("Error (1) adding item!\n", stderr);
	}
}

void show_pets(const Tree * ptree)
{
	if (tree_is_empty(ptree))
		puts("There are no records.");
	else
		traverse(ptree, print_item);
}

void print_item(Item output)
{
	printf("Animal: %-19s Kind: %-19s\n", 
		output.petname, output.petkind);
}

void find_pet(const Tree * ptree)
{
	Item temp;
	Trnode * find;

	if (tree_is_empty(ptree))
		puts("There are no entries.");
	else
	{
		puts("Enter the pet name of an animal that you want to find:");
		s_gets(temp.petname, STLEN);

		upper_case(temp.petname);
		upper_case(temp.petkind);

		if ((find = in_tree(ptree, &temp)))
			output_pets(find);
		else
			printf("There are no those pets!");
	}
}

void drop_pet(Tree * ptree)
{
	Item temp;

	if (tree_is_empty(ptree))
		puts("There are no records.");
	else
	{
		puts("Enter pet name of an animal you want to exclude from the club:");
		s_gets(temp.petname, STLEN);
		puts("Enter pet kind of the animal:");
		s_gets(temp.petkind, STLEN);

		upper_case(temp.petname);
		upper_case(temp.petkind);

		printf("%s named %s ", temp.petkind, temp.petname);
		if (delete_item(ptree, &temp))
			printf("excludes from the club.\n");
		else
			printf("isn't member of the club.\n");
	}
}

void upper_case(char * str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

char * s_gets(char * str, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(str, n, stdin);
	if (ret_val)
	{
		find = strchr(str, '\n');
		if (find)
			*find = '\0';
		else
			eatline();
	}

	return ret_val;
}

/* used with find_pet() user function only	*/
static void output_pets(const Trnode * pnode)
{
	int i;

	if (pnode)		/* <=> if (pnode != NULL) */
	{
		printf("pet name: %s\n", pnode->items[0].petname);
		for (i = 0; i < pnode->count; i++)
			printf("%5spet kind: %s\n","", pnode->items[i].petkind);
	}
}
