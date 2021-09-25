/* exercise2_support.c -- functions to support list operations 	*/
/* 						  compile with exercise2.c 				*/
#include <stdio.h>
#include <stdlib.h>
#include "exercise2.h"

/* prototype of static (local) function */
static void copy_to_node (Node * pnode, Item input);


/* interface functions */

/* sets the list to empty state */
void initialize_list (List * plist)
{
	plist->head = plist->end = NULL;
}

/* returns true, if the list is empty */
bool list_is_empty (const List * plist)
{
	bool ret_val;

	if (NULL == plist->head)
		ret_val = true;
	else
		ret_val = false;

	return ret_val;
}

/* returns true, if the list is full */
bool list_is_full (const List * plist)
{
	Node * pt;
	bool full;

	pt = (Node *) malloc(sizeof(Node));
	if (NULL == pt)
		full = true;
	else
		full = false;
	free(pt);

	return full;
}

/* returns the number of nodes */
unsigned int list_item_count (const List * plist)
{
	unsigned int count = 0;
	Node * pnode = plist->head;		/* setting to the beginning of the list */

	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;		/* setting to the next node */
	}

	return count;
}

/* creates a node for storing the element and adds it to the end 				*/
/* of the list specified by a variable of the plist type (slow implementation) 	*/
bool add_item (List * plist, Item item)
{
	Node * pnew;
	Node * current = plist->head;
	bool ret_val;

	pnew = (Node *) malloc(sizeof(Node));
	if (NULL == pnew)
		ret_val = false;				/* case of error 		*/
	else
	{
		ret_val = true;

		copy_to_node(pnew, item);
		pnew->next = NULL;

		if (NULL == current)			/* the list is empty, so put	*/
			plist->head = pnew;			/* pnew at the top of the list 	*/
		else
			plist->end->next = pnew;	/* adding pnew to the end		*/
		plist->end = pnew;
	}
	
	return ret_val;
}

/* visits each node and performs the function pointed to by pfun */
void traverse (const List * plist, void (* pfun) (Item output))
{
	Node * pnode = plist->head;		/* setting to the beginning of the list */

	while (pnode != NULL)
	{
		(*pfun)(pnode->item);		/* applying a function to an element	*/
		pnode = pnode->next;		/* move to the next item 				*/
	}
}

/* freeing memory allocated to by function malloc(), */
/* sets pointer of the list to NULL */
void empty_the_list (List * plist)
{
	Node * psave;

	while (plist->head != NULL)
	{
		psave = plist->head->next;		/* saving the address of the next node 	*/
		free(plist->head);				/* freeing of the current node 			*/
		plist->head = psave;			/* move to the next node 				*/
	}
}


/* definition of the static (local for this source file) function */

/* copies element to a node */
static void copy_to_node (Node * pnode, Item input)
{
	pnode->item = input;			/* copying of the structure */
}
