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
  LinkedList *llptr;                // create a pointer to the linked LinkedList
  LinkedList ll = {NULL};           // initialize a linked list
  llptr = &ll;                 // connect the pointer with the linked list
  return llptr;
}

// Adds a node to the front of the list, storing the given data in the node
void ll_push(LinkedList *l, void *data){
  // if the linkedlist is empty, create a new head.
  if (l->head == NULL){
    Node newhead = {NULL,NULL};
    l->head = &newhead;
  }
}
