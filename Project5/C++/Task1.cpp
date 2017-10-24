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

struct node
{
  node *next;
  float data;
};

class LinkedList
{
private:
  node *head;
  node *tail;
  int size;
public:
  // constructor
  LinkedList()
  {
    head = NULL;
    tail = NULL;
    size = 0;
  }

  node *gethead(){
    return head;
  }

  // adds a node to the front of the list, storing the given data in the node.
  void ll_push( float data ){
    node *newnode = new node;
    newnode->data = data;
    if ( size == 0 ){
      head = newnode;
      tail = newnode;
      newnode->next = NULL;
      size++;
    }
    else{
      node *oldhead = head;
      head = newnode;
      newnode->next = oldhead;
      size++;
    }
  }

  // removes the node at the front of the list and returns the associate data.
  void ll_pop(){
    if (head == NULL){

    }
    else if (size == 1){
      node *pop = head;
      head = NULL;
      tail = NULL;
      size--;

    }
    node *pop = head;
    head = pop->next;
    size--;
  }

  // adds a node to the end of the list, storing the given data in the node
  void ll_append( float data ){
    node *newnode = new node;
    newnode->data = data;
    if (size==0){
      head = newnode;
      tail = newnode;
      size++;
    }
    else {
      node *curnode = head;
      while (curnode->next!=NULL){
        curnode = curnode->next;
      }
      curnode->next = newnode;
      newnode->next = NULL;
      size++;
    }
  }

  // removes the first node in the list whos data matches target, freeing the associated data.
  void ll_remove(float target){
    if (size == 0){

    }
    else if (size == 1){
      node *curhead = head;
      if (curhead->data==target){
        delete curhead;
        head = NULL;
        tail = NULL;
        size--;
      }
      else{}
    }
    else{
      node *curhead = head;
      if (curhead->data == target){
        head = curhead->next;
        delete curhead;
        size--;
      }
      else{
        node *last = curhead;
        curhead = curhead->next;
        while (curhead!=NULL){
          if (curhead->data == target){
            last->next = curhead->next;
            delete curhead;
            size--;
          }
          else {
            curhead = curhead->next;
            last = last->next;
          }
        }
      }
    }
  }

  // returns the size of the list.
  int ll_size(){
    return size;
  }

  // removes all of the nodes from the list
  void ll_clear(){
    node *curhead = head;
    if (curhead == NULL){}
    else{
      while (curhead!=NULL){
        node *clear = curhead;
        curhead = curhead->next;
        delete clear;
      }
      head = NULL;
      tail = NULL;
      size = 0;
    }
  }

  // traverses the list and applies the give function to the data at each node.
  void ll_map(void (*mapfunc)(float)){
    node *cur = head;
    if (cur==NULL){

    }
    else{
      while (cur!=NULL){
        mapfunc(cur->data);
        cur = cur->next;
      }
    }
  }

  void ll_display(){
    node *cur = head;
    if (cur == NULL){
      std::cout<< "This list is empty!\n";
    }
    else {
      std::cout<< "Linked List: ";
      while (cur!=NULL){
        std::cout<< cur->data << " ";
        cur = cur->next;
      }
    }
    std::cout<< "\n";
  }
};

void square(float i){
  i = i*i;
}

int main(){
  LinkedList *ll = new LinkedList;
  int a = 24;
  ll->ll_push(a);
  //std::cout<< ll->gethead()->data << " ";
  ll->ll_display();
  return 0;
}
