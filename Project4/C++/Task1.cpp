/* Project 4
 * Part II: Semantics of Selected Languages
 *
 * Task1: What control flow statements does the language provide?
 * Write a program that uses all these control flow statements.
 *
 * Tracy Quan
 * 10/8/2017
 */
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int global = 24;

int main(){
	// selection statement: if and else
	std::cout << "------Selection statement: if and else-----\n";
	if (global != 24){
		std::cout << "Variable global is not 24\n";
	}
	else{
		std::cout << "Variable glbal is 24\n";
	}

	// iteration statements: do-while loop
	std::cout << "\n------Iteration statements: loops-----\n";
	string str;
	do{
		std::cout << "Enter text: ";
		getline (cin,str);
		std::cout << "Echo: " << str << "\n";
	} while (str!="goodbye");

	// jump statements: break
	std::cout << "\n------Jump statements: break-----\nCount down:";
	for (int i = 10; i > 0; i--){
		std::cout << "i = " << i << "\n";
		if (i==4){
			std::cout<<"Countdown aborted!\n";
			break;
		}
	}

	// jump statements: continue
	std::cout << "\n------Jump statements: continue-----\nSkip 4:";
	for (int n = 10; n > 0; n--){
		std::cout << "n = "<< n <<"\n";
		if (n == 4){
			continue;
		}
	}

	// another statement : switch
	std::cout << "\n------Switch-----\n";
	srand(time(NULL));
	int happy = rand()%2+1;
	switch (happy){
		case 2:
			std::cout << "Happy :D\n";
			break;
		case 1:
			std::cout << "Sad :C \n";
			break;
	}
	return 0;
}
