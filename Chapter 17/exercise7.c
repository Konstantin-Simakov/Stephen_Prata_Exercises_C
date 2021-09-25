/* exercise7.c -- Chapter 17 											*/
/*				  compile with exercise7_support.c 						*/
/* 				  use file.txt or create it before running the program 	*/
/* 				  and write any text inforamation into it				*/
#include <stdio.h>
#include <stdlib.h>			/* for exit(), EXIT_FAILURE 		*/
#include <string.h>			/* for strchr() 					*/
#include <ctype.h>			/* for tolower() 					*/
#include "exercise7.h"		/* for WRDLEN == 20, traverse()		*/

void eat_line (void);
char show_menu (void);
void word_list (const Tree * ptree);
void one_word_info (Item output);
void word_and_times (const Tree * ptree);

int main (void)
{
	FILE * fp;
	Item temp;
	Tree text;
	char choice;

	/* data initialization: tree and file 	    */
	initialize_tree(&text);
	if ((fp = fopen("file.txt", "r")) == NULL)
	{
		fputs("Cannot open file file.txt\n", stderr);
		exit(EXIT_FAILURE);
	}

	/* data reading from a file to the tree 	*/
	while (fscanf(fp, "%s", temp.word) == 1)
		add_item(&text, &temp);
	fclose(fp);

	/* data processing for tree 				*/
	while ((choice = show_menu()) != 'q')
		switch (choice)
		{
			case 't': word_list(&text);
				break;
			case 'w': word_and_times(&text);
				break;
			default : fputs("Error 1!\n", stderr);
		}

	/* data clearing for tree					*/
	delete_all(&text);
	puts("The program has been completed.");
	
	return 0;
}

/* prints the (sorted) contents of a binary search tree 	*/
/* note: the binary search tree sorts the items on its own!	*/
void word_list (const Tree * ptree)
{
	if (tree_is_empty(ptree))
		fputs("The text is empty!\n", stderr);
	else
	{
		traverse(ptree, one_word_info);
		printf("The number of different words in this text is %d.\n", 
			tree_item_count(ptree));
	}
}

void one_word_info (Item output)
{
	printf("word: %-*s\t times: %d\n", WRDLEN, output.word, output.num);
}

void word_and_times (const Tree * ptree)
{
	Item temp;
	Trnode * find;

	if (tree_is_empty(ptree))
		fputs("The text is empty!\n", stderr);
	else
	{
		puts("Enter a word:");
		if (scanf("%s", temp.word) != 1)
		{
			fputs("Incorrect word was entered.\n", stderr);
			exit(EXIT_FAILURE);
		}
		eat_line();

		find = in_tree(ptree, &temp);
		if (find)
			printf("word: %s, times: %d\n", find->item.word, find->item.num);
		else
			fputs("The word isn't in the text!\n", stderr);		
	}
}

char show_menu (void)
{
	int res;		/* if EOF is entered, the program should recognize it 	*/

	puts("Enter the number of action:");
	puts("t) text info    w) word info    q) quit the program");
	
	res = tolower(getchar());
	eat_line();
	while (strchr("twq", res) == NULL)
	{
		puts("You can enter t, w, q letters only. Try again:");
		res = tolower(getchar());
		eat_line();
	}

	return res;		/* implicit type conversion to char 					*/
}

void eat_line (void)
{
	while (getchar() != '\n')
		continue;
}
