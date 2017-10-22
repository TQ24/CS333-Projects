/* Project 5
 * Part I: Polymorphism
 * Task1
 *
 * Create a generic linked list class in C. First, create a LinkedList struct that
 * has a head pointer and a Node struct that can hold an arbitrary pointer and
 * a next pointer.
 */

#include <stdio.h>

typedef struct Node{
  struct Node *ptr;
  struct Node *next;
  void *data;
} Node;

typedef struct {
  Node *head;
  int size;
} LinkedList;

LinkedList *ll_create();

void ll_push(LinkedList *l, void *data);

void *ll_pop(LinkedList *l);

void ll_append(LinkedList *l, void *data);

void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *));

int ll_size(LinkedList *l);

void ll_clear(LinkedList *l, void (*freefunc)(void *));

void ll_map(LinkedList *l, void (*mapfunc)(void *));
