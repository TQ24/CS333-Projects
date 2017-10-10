#include <stdio.h>
#include <stdlib.h>

extern int CSTK_MAX;

typedef struct stack {
        int* stack;
        int top;
} Stack;


Stack *stk_create(int x);
    /* Creates a stack with the size specified by the int value. */


void stk_destroy (Stack* stk);
    /* Recycles a stack. */


void stk_push(Stack* stk, int n);
    /* Adds a new value to the top of the stack. */


int stk_pop(Stack* stk);
    /* Removes a value from the top of the stack. */


void stk_display(Stack* stk, int n);
    /* Prints out the list in the reverse order if the int value is 1, otherwise,
     * prints out the original order. */
