/* Project 4
 * Part II: Semantics of Selected Languages
 *
 * Task2: Function Type: write a program to shows how are functions treated in the
 * language as a data type? Name the program to task2.xx. Can you assign a function
 * to a variable? Can you pass a function to another function?
 *
 * Tracy Quan
 * 10/8/2017
 */

#include <iostream>
using namespace std;

int (*funcptr)(int,int);		//create a function pointer

int int_compare(int a, int b){
	if (a > b){
		std::cout << a << " is greater than " << b << "\n";
	}
	else if (a == b){
		std::cout << a << " equals " << b << "\n";
	}
	else if (a < b){
		std::cout << a << " is smaller than " << b << "\n";
	}
	return 0;
}

int main(){
	funcptr = &int_compare;
	(*funcptr)(8,24);
	return 0;
}
