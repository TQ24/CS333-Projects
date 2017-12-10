#include <iostream>
#include <cstring>
using namespace std;

int main(){
  // char pointer is new char[]
  char *char_ptr = new char[24];
  // char pointer is deleted by delete operator
  strcpy(char_ptr, "deleted by delete operator");
  // delete array char pointer
  delete[] char_ptr;
}
