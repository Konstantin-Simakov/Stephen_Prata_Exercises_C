/* exercise3_support.c -- functions to support list operations  */
/*                        compile with exercise3.c              */
#include <stdio.h>
#include <stdlib.h>
#include "exercise3.h"


/* interface functions */

/* sets the list to empty state (<=> sets any value of the list to oh) */
void initialize_list(List * plist)
{
    int i, j;

    for (i = 0; i < MAXSIZE; i++)
    {
        for (j = 0; j < TSIZE; j++)
            plist->entries[i].title[j] = '\0';  /* empty string -- member "title" for each item structure   */
        plist->entries[i].raiting = -2;         /* less than oh and no equals than EOF (-1)                 */
    }
    plist->items = 0;
}

/* returns true, if the list is empty */
bool list_is_empty(const List * plist)
{
    return 0 == plist->items ? true : false;
}

/* returns true, if the list is full */
bool list_is_full(const List * plist)
{
    return MAXSIZE == plist->items ? true : false;
}

/* returns the number of items */
unsigned int list_item_count(const List * plist)
{
    return plist->items;
}

/* adds new item to the end of a list (so as a list is the array of structures) */
bool add_item(List * plist, Item input)
{
    bool ret_val;

    if (list_is_full(plist))
        ret_val = false;
    else
    {
        plist->entries[plist->items] = input;
        plist->items++;
        ret_val = true;
    }

    return ret_val;
}

/* visits each node and performs the function pointed to by pfun */
void traverse(const List * plist, void (* pfun)(Item))
{
    int i;

    for (i = 0; i < plist->items; i++)
        (*pfun)(plist->entries[i]);
}

/* empties the list <=> peforms initialization of the list (in this case) */
void empty_the_list(List * plist)
{
    initialize_list(plist);
}
