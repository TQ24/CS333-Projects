/* Project3
 * Tracy Quan
 *
 * cstk.c
 */

#include "cstk.h"
#include <stdio.h>
#include <stdlib.h>

int CSTK_MAX = 50;

/* Creates a stack with the size specified by the int value. */
Stack *stk_create(int n){
      if (n>CSTK_MAX){
        printf("The capacity of the stack is 50");
        exit(0);
      }
      Stack *stk = malloc(sizeof(Stack));   //allocates the memory of Stack Structure
      stk->stack = malloc(n*sizeof(int)); //allocates the memory of int stack
      stk->top = -1;                      //assign the top to index -1

      return stk;
}

/* Recycles a stack. */
void stk_destroy(Stack* stk){
      free(stk);
      free(stk->stack);
      stk = NULL;
}

/* Adds a new value to the top of the stack. */
void stk_push(Stack* stk, int value){
      if (stk->top > CSTK_MAX-1){
        printf("The stack is FULL");
        exit(0);
      }
      stk->stack[stk->top+1] = value;
      stk->top = stk->top+1;
}

/* Removes a value from the top of the stack. */
int stk_pop(Stack* stk){
      if (stk->top<0){
        printf("The stack is empty");
        exit(0);
      }
      int pop = stk->stack[stk->top];
      stk->top = stk->top - 1;

      return pop;
}

/* Prints out the list in the reverse order if the int value is 1, otherwise,
 * prints out the original order. */
 void stk_display(Stack* stk, int reverse){
      if (reverse == 1){
        int i = stk->top;
        while (i>-1){
          printf("%d", stk->stack[i]);
          i--;
        }
      }
      else {
        for (int i=0; i <= stk->stack[stk->top]; i++){
          printf("%d", stk->stack[i]);
        }
      }
 }
