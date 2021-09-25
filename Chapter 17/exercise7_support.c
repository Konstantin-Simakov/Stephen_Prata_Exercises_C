/* exercise7_support.c -- tree support functions 	*/
/* 						  compile with exercise7.c 	*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>				/* for bool, true, false */
#include "exercise7.h"

/* local data type */
typedef struct pair {
	Trnode * parent;
	Trnode * child;		/* look.child is the item you are looking for */
} Pair;

/* prototypes of local (static) functions */
static Trnode * make_node (const Item * pi);
static bool to_left (const Item * i1, const Item * i2);
static bool to_right (const Item * i1, const Item * i2);
static void add_node (Trnode * new_node, Trnode * root);
static void in_order (const Trnode * root, void (* pfun) (Item output));
static Pair seek_node (const Tree * ptree, const Item * pi);
static void delete_node (Trnode ** ptr);
static void delete_all_nodes (Trnode * root);


/* function definitions */

void initialize_tree (Tree * ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}

bool tree_is_empty (const Tree * ptree)
{
	bool ret_val;

	if (NULL == ptree->root)
		ret_val = true;
	else
		ret_val = false;

	return ret_val;
}

bool tree_is_full (const Tree * ptree)
{
	Trnode * check;
	bool ret_val;

	check = (Trnode *) malloc(sizeof(Trnode));
	if (NULL == check)
		ret_val = true;
	else
		ret_val = false;
	free(check);

	return ret_val;
}

int tree_item_count (const Tree * ptree)
{
	return ptree->size;
}

bool add_item (Tree * ptree, const Item * pi)
{
	Trnode * new_node;
	bool ret_val;
	Pair look = seek_node(ptree, pi);

	if (tree_is_full(ptree))
	{
		fputs("The tree is full.\n", stderr);
		ret_val = false;
	}
	else if (look.child != NULL)
	{
		look.child->item.num++;			/* look.child -- has (Node *) type */
		ret_val = true;
	}
	else
	{
		new_node = make_node(pi);		/* points to a new node */
		if (NULL == new_node)
		{
			fputs("Failed to create a new node.\n", stderr);
			ret_val = false;
		}
		else	/* successful creation of a new node */
		{
			ret_val = true;
			
			ptree->size++;
			if (NULL == ptree->root)					/* case 1: the tree is empty 	*/
				ptree->root = new_node;					/* the new node is root 		*/
			else										/* case 2: the tree isn't empty */
				add_node(ptree->root, new_node);		/* adding a node to a tree 		*/
		}
	}

	return ret_val;
}

Trnode * in_tree (const Tree * ptree, const Item * pi)
{
	return seek_node(ptree, pi).child;
}

bool delete_item (Tree * ptree, const Item * pi)
{
	Pair look;
	bool ret_val;

	look = seek_node(ptree, pi);

	if (NULL == look.child)
		ret_val = false;
	else
	{
		ret_val = true;
		if (look.child->item.num > 1)
			look.child->item.num--;
		else  /* deleting of the node */
		{
			if (NULL == look.parent)
				delete_node(&ptree->root);
			else if (look.child == look.parent->left)
				delete_node(&look.parent->left);
			else
				delete_node(&look.parent->right);
			ptree->size--;
		}
	}

	return ret_val;
}

void traverse (const Tree * ptree, void (* pfun) (Item my_item))
{
	if (ptree != NULL)
		in_order(ptree->root, pfun);
}

void delete_all (Tree * ptree)
{
	if (ptree != NULL)
		delete_all_nodes(ptree->root);
	initialize_tree(ptree);				/* initialize the tree with empty content */
}


/* definition of local (static) functions */

static void in_order (const Trnode * root, void (* pfun) (Item))
{
	if (root != NULL)
	{
		in_order(root->left, pfun);
		(*pfun)(root->item);
		in_order(root->right, pfun);
	}
}

static void delete_all_nodes (Trnode * root)
{
	Trnode * pright;

	if (root != NULL)
	{
		pright = root->right;

		delete_all_nodes(root->left);
		free(root);
		delete_all_nodes(pright);
	}
}

static void add_node (Trnode * root, Trnode * new_node)
{
	if (to_left(&new_node->item, &root->item))
	{
		if (NULL == root->left)					/* it is empty subtree 			*/
			root->left = new_node;				/* so add the node here 		*/
		else
			add_node(root->left, new_node);		/* else process the subtree 	*/
	}
	else if (to_right(&new_node->item, &root->item))
	{
		if (NULL == root->right)
			root->right = new_node;
		else
			add_node(root->right, new_node);
	}
	else  										/* Error case! 					*/
	{
		fputs("Location error in add_node().\n", stderr);
		exit(EXIT_FAILURE);
	}
}

static bool to_left (const Item * i1, const Item * i2)
{
	bool ret_val;

	if (strcmp(i1->word, i2->word) < 0)
		ret_val = true;
	else
		ret_val = false;

	return ret_val;
}

static bool to_right (const Item * i1, const Item * i2)
{
	bool ret_val;

	if (strcmp(i1->word, i2->word) > 0)
		ret_val = true;
	else
		ret_val = false;

	return ret_val;
}

static Trnode * make_node (const Item * pi)
{
	Trnode * new_node;

	new_node = (Trnode *) malloc(sizeof(Trnode));
	if (new_node != NULL)
	{
		new_node->item = *pi;
		new_node->item.num = 1;		/* new word is the first */
		new_node->left = NULL;
		new_node->right = NULL;
	}

	return new_node;
}

/* look.child is the item you are looking for */
static Pair seek_node (const Tree * ptree, const Item * pi)
{
	Pair look;

	look.parent = NULL;
	look.child = ptree->root;

	while (look.child != NULL)
	{
		if (to_left(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (to_right(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else  		/* if the element is located neither to the left nor to the right, then it is the same; */
			break;		/* note: look.child is the address of the node containing the item pointed by pi */
	}

	return look;
}

/* ptr is the address of the parent node pointing		*/
/* to the target (child) node (the node to be removed)	*/
static void delete_node (Trnode ** ptr)
{
	Trnode * temp;

	if (NULL == (*ptr)->left)
	{
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	}
	else if (NULL == (*ptr)->right)
	{
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
	else  			/* the node to be removed has 2 child nodes */
	{
		/* search for the place (address) of joining the right subtree */
		for (temp = (*ptr)->left; temp->right != NULL; 
				temp = temp->right)
			continue;
		temp->right = (*ptr)->right;
		
		temp = *ptr;
		*ptr = (*ptr)->left;	
		free(temp);
	}
}
