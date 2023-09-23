/* exercise4.h -- queue interface */
#ifndef EXERCISE4_H_
#define EXERCISE4_H_

#include <stdbool.h>    /* for bool, true, false    */

/* HERE YOU NEED INSERT ITEM TYPE DEFINITION */
/* FOR EXAMPLE, */
typedef struct item {
    long arrive;
    int process_time;
} Item;
/* OR typdef struct item {int gumption; int charisma;} Item; */

#define MAXQUEUE 10

typedef struct node {
    Item item;
    struct node * next;
} Node;

typedef struct queue {
    Node * front;       /* pointer to the beginning of the queue */
    Node * rear;        /* pointer to the end of the queue */
    int items;          /* number of elements in the queue */
} Queue;

/* operation:       queue initialization                                    */
/* preconditions:   pq points to the queue                                  */
/* postconditions:  the queue has initialized with empty content            */
void initialize_queue(Queue * pq);

/* operation:       checking if the queue is full                           */
/* preconditions:   pq points to a previously initialized queue             */
/* postconditions:  returns true if the queue is full and false otherwise   */
bool queue_is_full(const Queue * pq);

/* operation:       checking is the queue is empty                          */
/* preconditions:   pq points to a previously initialized queue             */
/* postconditions:  returns true if the queue is empty and false otherwise  */
bool queue_is_empty(const Queue * pq);

/* operation:       definition of the number of elements in the queue       */
/* preconditions:   pq points to a previously initialized queue             */
/* postconditions:  returns the number of elements in the queue             */
int queue_item_count(const Queue * pq);

/* operation:       adding an item to the end of the queue                  */
/* preconditions:   pq points to a previously initialized queue;            */
/*                  the item must be place at the end of the queue          */
/* postconditions:  if the queue is not empty, the item is placed           */
/*                  at the end of the queue and the function returns true;  */
/*                  otherwise the queue remains unchanged                   */
/*                  and the function returns false                          */
bool en_queue(Queue * pq, Item my_item);

/* operation:       deleting an item from the beginning of the queue        */
/* preconditions:   pq points to a previously initialized queue             */
/* postconditions:  if the queue is not empty, the item at the head         */
/*                  of the queue is copied to *pitem and removed from       */
/*                  the queue and the function returns true;                */
/*                  if the operation empties the queue, the queue           */
/*                  is reset to an empty state.                             */
/*                  If the queue is empty from the beginning, it remains    */
/*                  unchanged and the function returns false                */
bool de_queue(Item * pitem, Queue * pq);

/* operation:       emptying the queue                                      */
/* preconditions:   pq points to a previously initialized queue             */
/* postconditions:  the queue is empty                                      */
void empty_the_queue(Queue * pq);

/* operation:       output of the queue content                             */
/* preconditions:   pq points to a previously initialized queue,            */
/*                  pfun points to a function that takes an Item argument   */
/*                  and has no return vlaue                                 */
/* postconditions:  the function that was pointed by pfun executes one time */
/*                  for every item in the queue                             */
void traverse_q(const Queue * pq, void (* pfun)(Item));

#endif
