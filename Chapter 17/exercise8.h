/* exercise8.h -- binary search tree							 	*/
/*			 	  duplicated elements in this tree are not allowed 	*/
#ifndef EXERCISE8_H_
#define EXERCISE8_H_

#include <stdbool.h>
#define STLEN 20

/* redefinition of Item type appropriately */
typedef struct item {
	char petname[STLEN];
	char petkind[STLEN];
} Item;

#define MAXITEMS 20

typedef struct trnode {
	Item items[MAXITEMS];
	int count;					/* current number of items 	*/
	struct trnode * left;		/* pointer to left branch 	*/
	struct trnode * right;		/* pointer to right branch 	*/
} Trnode;

typedef struct tree {
	Trnode * root;				/* pointer to root of the tree */
	int size;					/* number of elements in the tree */
} Tree;


/* function prototypes */

/* operation:		initialization of tree with empty content 			*/
/* preconditions:	ptree points to the tree 							*/
/* postconditions:	ptree sets to empty			 						*/
void initialize_tree (Tree * ptree);

/* operation:		determining if the tree is empty					*/
/* preconditions:	ptree points to the tree 							*/
/* postconditions:	the function returns true if the tree 				*/
/*					is empty and false otherwise						*/
bool tree_is_empty (const Tree * ptree);

/* operation:		determining if the tree is full						*/
/* preconditions:	ptree points to the tree 							*/
/* postconditions:	the function returns true if the tree 				*/
/* 					is full and false otherwise							*/
bool tree_is_full (const Tree * ptree);

/* operation:		determining the number of items in the tree 		*/
/* preconditions:	ptree points to the tree 							*/
/* postconditions:	the function returns the number of items			*/
int tree_item_count (const Tree * ptree);

/* operation:		adding item to the tree 							*/
/* preconditions:	pi is the address of the added item 				*/
/* 					ptree points to initialized tree 					*/
/* postconditions:	if possible, the function adds item 				*/
/* 					to the tree and returns true; 						*/
/* 					otherwise it returns false 							*/
bool add_item (Tree * ptree, const Item * pi);

/* operation:		searching for an item in the tree 					*/
/* preconditions:	pi points to an item 								*/
/*					ptree points to initialized tree 					*/
/* postconditions:	the function returns pointer to a node  			*/
/* 					if the item is in the tree and false otherwise		*/
Trnode * in_tree (const Tree * ptree, const Item * pi);

/* operation:		deleting an item from the tree 						*/
/* preconditions:	pi is the address of deleted item 					*/
/* 					ptree points to initialized tree 					*/
/* postconditions:	if possible, the function deletes the item 			*/
/* 					from the tree and returns true; 					*/
/* 					otherwise the function returns false 				*/
bool delete_item (Tree * ptree, const Item * pi);

/* operation:		application of pointed function to every item 		*/
/*					in the tree 										*/
/* preconditions:	ptree points to the tree 							*/
/*					pfun points to a function that takes 				*/
/*					an Item argument and has no return value 			*/
/* postconditions:	the function specified with pfun is executed once 	*/
/*					for each item in the tree 							*/
void traverse (const Tree * ptree, void (* pfun) (Item item));

/* operation:		deleting all items from the tree 					*/
/* preconditions:	ptree points to initialized tree 					*/
/* postconditions:	the tree is empty 									*/
void delete_all (Tree * ptree);

#endif				/* is it necessarily! */
