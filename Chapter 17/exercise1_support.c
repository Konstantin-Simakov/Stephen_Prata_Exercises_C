/* exercise1_support.c -- functions to support doubly list operations   */
/*                        compile with exercise1.c                      */
#include <stdio.h>
#include <stdlib.h>
#include "exercise1.h"

/* prototype of static (local) function */
static void copy_to_node(Node * pnode, Item input);

/* interface functions                  */
/* sets the list to empty state         */
void initialize_list(List * plist)
{
    plist->head = plist->tail = NULL;
}

/* returns true, if the list is empty   */
bool list_is_empty(const List * plist)
{
    bool ret_val;

    if (NULL == plist->head)
        ret_val = true;
    else
        ret_val = false;

    return ret_val;
}

/* returns true, if the list is full    */
bool list_is_full(const List * plist)
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

/* returns the number of nodes          */
unsigned int list_item_count(const List * plist)
{
    Node * current = plist->head;
    unsigned int count = 0;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}

/* creates a node for storing the item and adds it to the end                   */
/* of the list specified by a variable of the plist type (slow implementation)  */
bool add_item(List * plist, Item item)
{
    bool ret_val;
    Node * new_node;
    Node * current;

    current = plist->head;
    new_node = (Node *) malloc(sizeof(Node));
    
    if (NULL == new_node)
        ret_val = false;
    else    /* successful memeory allocation */
    {
        ret_val = true;

        copy_to_node(new_node, item);
        new_node->next = NULL;
        if (NULL == current)
        {
            new_node->prev = NULL;
            plist->head = new_node;
        }
        else
        {
            new_node->prev = plist->tail;
            plist->tail->next = new_node;
        }
        plist->tail = new_node;
    }

    return ret_val;
}

/* visits each node from "head" to "tail" of the list   */
/* and performs the function pointed to by pfun         */
void traverse_direct(const List * plist, void (* pfun)(Item output))
{
    Node * front = plist->head;     /* setting to the beginning of the list */
    
    while (front != NULL)
    {
        (*pfun)(front->item);       /* applying a function to an item       */
        front = front->next;        /* move to the next item                */
    }
}

/* visits each node from "tail" to "head" of the list   */
/* and performs the function pointed to by pfun         */
void traverse_reverse(const List * plist, void (* pfun)(Item output))       /* just the declaration */
{
    Node * end = plist->tail;

    while (end != NULL)
    {
        (*pfun)(end->item);         /* it is the member of the structure Node */
        end = end->prev;
    }
}

/* freeing memory allocated to by function malloc(),    */
/* sets pointer of the list to NULL                     */
void empty_the_list(List * plist)
{
    Node * psave;

    while (plist->head != NULL)
    {
        psave = plist->head->next;  /* saving the address of the next node */
        free(plist->head);          /* freeing of the current node */
        plist->head = psave;        /* move to the next node */
    }
}

/* definition of the static (local for this source file) function   */
/* copies item to a node                                            */
static void copy_to_node(Node * pnode, Item input)
{
    pnode->item = input;            /* copying of the structure */
}
