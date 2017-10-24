/* Project 5
 * Part I: Polymorphism
 * Task1
 * C++
 *
 * Create a generic linked list class in C. First, create a LinkedList struct that
 * has a head pointer and a Node struct that can hold an arbitrary pointer and
 * a next pointer.
 */

#include <iostream>
using namespace std;

typedef struct Node {
  sturct Node *next;
  void *data;
} Node;

class LinkedList {
  Private:
  Node *head;
  Node *tail;
  int size;

  Public:
  // constructor
  LinkedList(){
    this.head = NULL;
    this.tail = NULL;
    this.size = 0;
  }

  // adds a node to the front of the list, storing the given data in the node.
  void ll_push( void *data ){
    Node newnode = new Node();
    newnode->data = data;
    if ( this.size == 0 ){
      this.head = newnode;
      this.tail = newnode;
      this.size++;
    }
    else{
      Node *oldhead = this.head;
      this.head = newnode;
      newnode->next = oldhead;
      this.size++;
    }
  }

  // removes the node at the front of the list and returns the associate data.
  void *ll_pop(){
    if (this.head == NULL){
      return NULL;
    }
    else if (this.size == 1){
      Node *pop = this.head;
      this.head = NULL;
      this.tail = NULL;
      this.size--;
      return pop->data;
    }
    Node *pop = this.head;
    this.head = pop->next;
    this.size--;
    return pop->data;
  }

  int main(){
    LinkedList ll = new LinkedList();
    int *a = 24;
    std::cout<< ll.head->data <<;
  }


}
