/* exercise5.h -- header file for stack (ADT) */
#ifndef EXERCISE5_H_
#define EXERCISE5_H_

#include <stdbool.h>        /* for bool, true, false    */


/* program specific declarations                        */

typedef char Item;

typedef struct node {
    Item item;
    struct node * next;
} Node;

typedef struct stack {
    Node * head;
    Node * tail;
} Stack;


/* function prototypes */

/* operation:       stack initialization                                */
/* preconditions:   ps points to the stack                              */
/* postconditions:  the stack has initialized with empty value          */
void stack_initialize(Stack * ps);

/* operation:       checking if the stack is full                       */
/* preconditions:   ps points to a previously initialized stack         */
/* postconditions:  the function returns true if the stack is full;     */
/*                  otherwise, it returns false                         */
bool stack_is_full(const Stack * ps);

/* operation:       checking if the stack is empty                      */
/* preconditions:   ps points to a previously initialized stack         */
/* postconditions:  the function returns true if the stack is empty;    */
/*                  otherwise, it returns false                         */
bool stack_is_empty(const Stack * ps);

/* operation:       pushes an item to a stack                           */
/* preconditions:   ps points to a previously initialized stack         */
/*                  "input" must be placed on the top of the stack      */
/*                  (that is, at the end of the given linked list)      */
/* postconditions:  if the stack isn't full, "input" places on the top  */
/*                  of the stack and the function returns true;         */
/*                  otherwise, the stack remains unchanged              */
/*                  and the function returns false                      */
bool push(Stack * ps, Item * input);

/* operation:       deletes an item from the top of the stack           */
/* preconditions:   ps points to a previously initialized stack         */
/* postconditions:  if the stack isn't empty, item on the top           */
/*                  of the stack is copied to *pitem and deleted        */
/*                  from the stack and the function returns true;       */
/*                  if the operation empties the stack,                 */
/*                  it is reset to the empty value (state)              */
/*                  (and the function also returns true)                */
/*                  if the stack was empty from the beginning,          */
/*                  it remains unchanged and the function returns false */
bool pop(Stack * ps, Item * pitem);

/* operation:       empty the stack                                     */
/* preconditions:   ps points to initialized stack                      */
/* postconditions:  deletes all content of the stack                    */
/*                  and sets the stack to the empty state               */
void empty_the_stack(Stack * ps);

#endif
