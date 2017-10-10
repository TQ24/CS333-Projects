/* Project3 Task1
 * Tracy Quan
 *
 *
 * C++
 * Task1:Write an example program in each language that demonstrates the rules
 * for identifier naming, variable declarations and identifier scoping.
 * Focus on any special rules or capabilities of your language.
 */

#include <iostream>
#include <string>
using namespace std;

int number = 24; //global variable declaration
//int 1number = 24;  Compile error: variable name can't start with a digit

int foo(){
  int number = 8; //local variable declaration
  return number;
}

int string_test(){
  string str1 = "Hello";
  string str2 = "World";
  string str3 = str1+" "+str2;
  cout << "str1 : " << str1 << "\n";
  cout << "str2 : " << str2 << "\n";
  cout << "str1 + str2 : " << str3 << endl;
  return 0;
}

int main(){

  printf("Value of variable number: %d\n",foo() );
  printf("%c\n",string_test());


  return 0;
}
