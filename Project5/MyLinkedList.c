/* Project 5
 * Part I: Polymorphism
 * Task1
 *
 * Create a generic linked list class in C. First, create a LinkedList struct that
 * has a head pointer and a Node struct that can hold an arbitrary pointer and
 * a next pointer.
 */

 #include <stdio.h>

typedef struct {
  Node *head;
} LinkedList;

typedef struct {
  Node *ptr;
  Node *next;
  int data;
} Node;

// Creates a new LinkedList struct, initializes it, and returns it.
LinkedList *ll_create(){
  LinkedList *llptr = malloc(sizeof(LinkedList));   // create a pointer to the linked LinkedList
  llptr->head = NULL;
  return llptr;
}

// Adds a node to the front of the list, storing the given data in the node
void ll_push(LinkedList *l, void *data){
  // if the linkedlist is empty, create a new head.
  if (l->head == NULL){
    Node *newhead;
    newhead = (Node *)malloc(sizeof(Node));
    newhead->data = data;
    newhead->next = NULL;
  }
  Node *prevhead;       //store the old head Node
  prevhead = l->head;
  Node *newhead;
  newhead = (Node *)malloc(sizeof(Node));
  newhead->data = data;
  l->head = newhead;    //head point to the new head
  newhead->next = prevhead;
}

// removes the node at the front of the list and returns the associate data.
void *ll_pop(LinkedList *l){
  Node *pop;
  pop = l->head;
  l->head = pop->next;
  return pop->data;
}
