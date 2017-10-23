/* Project 5
 * Part I: Polymorphism
 * Task1
 *
 * Create a generic linked list class in C. First, create a LinkedList struct that
 * has a head pointer and a Node struct that can hold an arbitrary pointer and
 * a next pointer.
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// Creates a new LinkedList struct, initializes it, and returns it.
LinkedList *ll_create(){
  LinkedList *llptr = malloc(sizeof(LinkedList));   // create a pointer to the linked LinkedList
  llptr->head = NULL;
  llptr->size = 0;
  return llptr;
}

// Adds a node to the front of the list, storing the given data in the node
void ll_push(LinkedList *l, void *data){
  // if the linkedlist is empty, create a new head.
  if (l->head == NULL){
    Node *newhead;
    newhead = (Node *)malloc(sizeof(Node));
    newhead->data = data;
    l->head = newhead;
    newhead->next = NULL;
    l->size++;
  }
  else{
    Node *prevhead;       //store the old head Node
    prevhead = l->head;
    Node *newhead;
    newhead = (Node *)malloc(sizeof(Node));
    newhead->data = data;
    l->head = newhead;    //head point to the new head
    newhead->next = prevhead;
    l->size++;
  }
}

// removes the node at the front of the list and returns the associate data.
void *ll_pop(LinkedList *l){
  if (l->head == NULL){
    return NULL;
  }
  else if (l->size == 1){
    Node *pop = l->head;
    l->head = NULL;
    l->size--;
    free(pop);
    return pop->data;
  }
  Node *pop;
  pop = l->head;
  l->head = pop->next;
  l->size--;
  free(pop);
  return pop->data;
}

// adds a node to the end of the list, storing the given data in the node.
void ll_append(LinkedList *l, void *data){
  if (l->size == 0){
    Node *newnode = malloc(sizeof(Node));
    l->head = newnode;
    newnode->data = data;
    newnode->next = NULL;
    l->size++;
  }
  else{
    Node *newnode = malloc(sizeof(Node));
    newnode->data = data;
    Node *h = l->head;
    while (h->next!=NULL){
      h = h->next;
    }
    h->next = newnode;
    newnode->next = NULL;
    l->size++;
  }
}

/* removes the first node in the list whose data matches target given the comparition function.
 * the function returns the pointer to the data.
 */
void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *)){
  Node *current = l->head;
  if (current == NULL){
    return NULL;
  }
  else if (l->size == 1){
    if (compfunc(current->data,target) == 1){
      return current->data;
    }
    return NULL;
  }
  else if (compfunc(current->data, target) == 1){
    return current->data;
  }
  Node *last = current;
  current = current->next;
  while (current != NULL){
    if (compfunc(current->data, target) == 1){
      Node *next = current->next;
      last->next = next;
      l->size--;
      return current->data;
    }
    last = last->next;
    current = current->next;
  }
  return NULL;
}

// returns the size of the list
int ll_size(LinkedList *l){
  return l->size;
}

// removes all of the nodes from the list, freeing the associated data using given function.
void ll_clear(LinkedList *l, void (*freefunc)(void *)){
  Node *cur = l->head;
  if (cur == NULL){
    printf("%s\n", "It's empty");
    return;
  }
  while (cur != NULL ){
    Node *clear = cur;
    cur = cur->next;
    free(clear);
  }
  l->head = NULL;
  l->size = 0;
}

// traverses the list and applies the given function to the data at each node.
void ll_map(LinkedList *l, void (*mapfunc)(void *)){
  Node *current = l->head;
  if (current == NULL){
    return;
  }
  else{
    while (current != NULL){
      mapfunc(current->data);
      current = current->next;
    }
  }
}
