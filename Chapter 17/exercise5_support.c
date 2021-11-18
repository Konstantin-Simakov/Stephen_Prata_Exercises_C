/* exercise5_support.c -- functions to support stack operations */
/* 						  compile with exercise5.c 				*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "exercise5.h"

/* local (static) function prototypes */
static void copy_to_node(Node * pn, const Item * pi);
static void copy_to_item(Item * pi, const Node * pn);

void stack_initialize(Stack * ps)
{
	ps->head = ps->tail = NULL;
}

bool stack_is_full(const Stack * ps)
{
	bool full;
	Node * pnode;

	pnode = (Node *) malloc(sizeof(Node));
	if (NULL == pnode)
		full = true;
	else
		full = false;
	free(pnode);

	return full;
}

bool stack_is_empty(const Stack * ps)
{
	bool empty;

	if (NULL == ps->head)
		empty = true;
	else
		empty = false;

	return empty;
}

bool push(Stack * ps, Item * input)
{
	bool ret_val;
	Node * pnode;

	if (stack_is_full(ps))
		ret_val = false;
	else
	{
		pnode = (Node *) malloc(sizeof(Node));
		if (NULL == pnode)
		{
			fputs("Failed to allocate memory!\n", stderr);
			exit(EXIT_FAILURE);
		}
		ret_val = true;

		copy_to_node(pnode, input);	/* copying an item member to node 							*/
		pnode->next = NULL;			/* set next pointer as the last node in the list (stack) 	*/

		if (NULL == ps->head)		/* case 1: stack is empty initially 						*/
			ps->head = pnode;		
		else						/* case 2: stack is not empty initially 					*/
			ps->tail->next = pnode;
		ps->tail = pnode;
	}

	return ret_val;
}

bool pop(Stack * ps, Item * pitem)
{
	bool ret_val;
	Node * temp, * prev;

	if (stack_is_empty(ps))
		ret_val = false;
	else
	{
		ret_val = true;

		copy_to_item(pitem, ps->tail);

		if (ps->head == ps->tail)
		{
			free(ps->head);
			stack_initialize(ps);		/* setting of the stack to the empty state */
		}
		else
		{
			temp = ps->tail;
								/* find the node preceding the deleted one */
			for (prev = ps->head; prev->next != ps->tail; prev = prev->next)
				continue;
			ps->tail = prev;
			free(temp);
		}
	}

	return ret_val;
}

void empty_the_stack(Stack * ps)
{
	Item dummy;

	while (!stack_is_empty(ps))
		pop(ps, &dummy);			/* delete the item -- using of the pop() function */
}


/* local (static) functions */

static void copy_to_node(Node * pn, const Item * pi)
{
	pn->item = *pi;
}

static void copy_to_item(Item * pi, const Node * pn)
{
	*pi = pn->item;
}
