/* exercise1_version2.h -- header file for simple list type */
#ifndef EXERCISE1_VERSION2_H_
#define EXERCISE1_VERSION2_H_

#include <stdbool.h>		/* functionality of the C99 standard 				*/


/* program specific declarations 	*/

#define TSIZE		45		/* the size of the array for storing the title 		*/

struct film {
	char title[TSIZE];
	int raiting;
};

/* generic type definitions 		*/
typedef struct film Item;

typedef struct node {
	Item item;
	struct node * next;
} Node;

typedef Node * List;


/* function prototypes 				*/

/* operation:		initialization of list 										*/
/* preconditions:	plist points to the list 									*/
/* postconditions: 	the list has initialized of empty content 					*/
void initialize_list(List * plist);

/* operation:		determining if the list is empty 							*/
/* preconditions:	plist points to initialized list 							*/
/* postconditions: 	the function returns true if the list  						*/
/* 					is empty and false otherwise 								*/
bool list_is_empty(const List * plist);

/* operation:		determining if the list is full 							*/
/* preconditions:	plist points to initialized list 							*/
/* postconditions: 	the function returns true if the list 						*/
/* 					is full and false otherwise 								*/
bool list_is_full(const List * plist);

/* operation:		determining of the number of elements in the list 			*/
/* preconditions:	plist points to initialized list 							*/
/* postconditions: 	the function returns the number of item in the list 		*/
unsigned int list_item_count(const List * plist);

/* operation:		adding an item to the end of the list 						*/
/* preconditions:	item is an item adding to the list 							*/
/*					plist points to initialized list 							*/
/* postconditions:	if possible the function adds an item to 					*/ 
/*					the end of the list and returns true;						*/
/*					otherwise, it returns false									*/
bool add_item(List * plist, Item input);

/* operation:		using of the function to the every item of the list 		*/
/* preconditions:	plist points to initialized list, 							*/
/*					pfun points to a function that takes 						*/
/*					an Item argument and has no return value					*/
/* postconditions:	the function that was showed by pfun executes one 			*/
/*					time for every item in direct oreder 						*/
void traverse_direct(const List * plist, void (* pfun)(Item output));

/* operation:		using of the function to the every item of the list 		*/
/* preconditions:	plist points to initialized list, 							*/
/*					pfun points to a function that takes 						*/
/*					an Item argument and has no return value					*/
/* postconditions:	the function that was showed by pfun executes one 			*/
/*					time for every item in reverse oreder 						*/
void traverse_reverse(const List * plist, void (* pfun)(Item output));

/* operation:		freeing the allocated memory, if any						*/
/* preconditions: 	plist points to initialized list 							*/
/* postconditions: 	any memory allocated for the list 							*/
/*					is freed and the list is set to 							*/
/*					an empty state (the memory 									*/
/*					allocated for it is outside the program's purview) 			*/
void empty_the_list(List * plist);

#endif
