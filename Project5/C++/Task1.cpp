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
      else{
        std::cout<<"Target not found!\n";
      }
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
            return;
          }
          else {
            curhead = curhead->next;
            last = last->next;
          }
        }
        std::cout<<"Target not found!\n";
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
  void ll_map(void (*mapfunc)(float *)){
    node *cur = head;
    if (cur==NULL){

    }
    else{
      while (cur!=NULL){
        float *a = &cur->data;
        mapfunc(a);
        cur = cur->next;
      }
    }
  }

  // removes the node at any position in the list EXTENSION1
  void ll_delete(int index){
    if (head == NULL){
      return;
    }
    if (index >= size || index<0){
      return;
    }
    else{
      if (size==1){
        head = NULL;
        tail = NULL;
        size--;
      }
      else{
        node *c = head;
        if (index == 0){
          head = c->next;
        }
        else{
          node *last = c;
          c = c->next;
          for (int i=1; i<index; i++){
            c = c->next;
            last = last->next;
          }
          last->next = c->next;
        }
        size--;
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

void square(float *i){
  *i = *i * *i;
}

int main(){
  LinkedList *ll = new LinkedList;
  std::cout<<"---Integer Linked List---\n";
  int a = 24;
  ll->ll_push(a);
  a = 32;
  ll->ll_push(a);
  a = 99;
  ll->ll_push(a);
  std::cout<<"After pushing:\n";
  ll->ll_display();
  a = 8;
  ll->ll_append(a);
  std::cout<<"After appending:\n";
  ll->ll_display();
  ll->ll_remove(99);
  ll->ll_remove(88);
  std::cout<<"After removing:\n";
  ll->ll_display();
  ll->ll_map(square);
  std::cout<<"After squaring:\n";
  ll->ll_display();
  ll->ll_clear();
  std::cout<<"After clearing:\n";
  ll->ll_display();

  LinkedList *ll2 = new LinkedList;
  std::cout<<"\n---Float Linked List---\n";
  float b = 24.4;
  ll2->ll_push(b);
  b = 32.2;
  ll2->ll_push(b);
  b = 99.9;
  ll2->ll_push(b);
  std::cout<<"After pushing:\n";
  ll2->ll_display();
  b = 8.8;
  ll2->ll_append(b);
  std::cout<<"After appending:\n";
  ll2->ll_display();
  ll2->ll_remove(99.9);
  ll2->ll_remove(88.8);
  std::cout<<"After removing:\n";
  ll2->ll_display();
  ll2->ll_map(square);
  std::cout<<"After squaring:\n";
  ll2->ll_display();
  ll2->ll_delete(2);
  std::cout<<"After deleting:\n";
  ll2->ll_display();
  ll2->ll_clear();
  std::cout<<"After clearing:\n";
  ll2->ll_display();

  return 0;
}
