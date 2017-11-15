/* Project 6
 * Part 2: File I/O and String in C++
 * Task2: Functions
 * Tracy Quan
 *
 * Functions in C++
 */

#include <iostream>
using namespace std;

int func_overload(int a, int b){
  return a+b;
}

int func_overload(int a, int b, int c){
  return a-b+c;
}

int main(){
  int a = 3;
  int b = 5;
  int c = 8;
  int d;
  d = func_overload(a, b);
  std::cout<<d<<"\n";
  d = func_overload(a, b, c);
  std::cout<<d;
}
