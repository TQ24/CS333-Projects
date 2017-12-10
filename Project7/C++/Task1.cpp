/* CS333
 * Project 7
 *
 * Part2
 * C++
 * Memory allocation and deallocation
 */

#include <iostream>
using namespace std;


int main(){
  // initialize the memory using new operator
  int *p = new int(24);
  char *c = new char('c');
  float *f = new float(24.8);

  // allocate block of Memory
  int *a = new int[8];
  // delete
  delete p;
  delete c;
  delete f;

  // demo: deallocate an array
  int *lst = new int[24];         // dynamic array
  delete[] lst;                   // deallocates the array
  lst = 0;                        // reset list to null pointer

  // check memory availability
  int *n = new int;
  if (!n){
    cout<< "allocation of memory failed!";
  }
  else{
    *n = 24;
    cout<<"Value of n is "<<*n;
  }
}
