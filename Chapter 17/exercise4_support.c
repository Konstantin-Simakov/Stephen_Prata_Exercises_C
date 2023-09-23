/* exercise4_support.c -- realization of the Queue type (ADT) */
#include <stdio.h>
#include <stdlib.h>
#include "exercise4.h"

/* local (static) functions */
static void copy_to_node(Node * pn, Item my_item);
static void copy_to_item(Item * pi, Node * pn);

void initialize_queue(Queue * pq)
{
    pq->front = pq->rear = NULL;
    pq->items = 0;
}

bool queue_is_full(const Queue * pq)
{
    return MAXQUEUE == pq->items;
}

bool queue_is_empty(const Queue * pq)
{
    return 0 == pq->items;
}

int queue_item_count(const Queue * pq)
{
    return pq->items;
}

bool en_queue(Queue * pq, Item my_item)
{
    Node * pnew;
    bool ret_val;

    if (queue_is_full(pq))
        ret_val = false;
    else
    {
        ret_val = true;

        pnew = (Node *) malloc(sizeof(Node));
        if (NULL == pnew)
        {
            fputs("Failed to allocate memory!\n", stderr);
            exit(EXIT_FAILURE);
        }

        copy_to_node(pnew, my_item);            /* initialization of new node                       */
        pnew->next = NULL;                      /* initialization of new node (continuation)        */

        if (queue_is_empty(pq))
            pq->front = pnew;                   /* my_item places at the beginning of the queue     */
        else
            pq->rear->next = pnew;              /* linking a new queue node to its end              */
        pq->rear = pnew;                        /* end of queue location writing                    */
        pq->items++;                            /* increase by 1 the number of items in the queue   */
    }

    return ret_val;
}

bool de_queue(Item * pitem, Queue * pq)
{
    Node * pt;                                  /* temporary pointer */
    bool ret_val;

    if (queue_is_empty(pq))
        ret_val = false;
    else
    {
        ret_val = true;

        copy_to_item(pitem, pq->front);

        pt = pq->front;
        pq->front = pq->front->next;
        free(pt);

        pq->items--;
        if (0 == pq->items)
            pq->rear = NULL;
    }

    return ret_val;
}

/* emptying of the queue */
void empty_the_queue(Queue * pq)
{
    Item dummy;                                 /* dummy variable -- for de_queue() correct working */

    while (!queue_is_empty(pq))
        de_queue(&dummy, pq);
}

void traverse_q(const Queue * pq, void (* pfun)(Item))
{
    Node * current = pq->front;

    while (current != NULL)
    {
        (*pfun)(current->item);
        current = current->next;
    }
}


/* local (static) functions */

static void copy_to_node(Node * pn, Item my_item)
{
    pn->item = my_item;
}

static void copy_to_item(Item * pi, Node * pn)
{
    *pi = pn->item;
}
