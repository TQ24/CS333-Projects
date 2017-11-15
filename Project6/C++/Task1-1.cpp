/* Project 6
 * Part 2: File I/O and String in C++
 * Task1-1: Inputs from command line and standard input.
 * Tracy Quan
 *
 * User input information into the program interactively.
 */

#include <iostream>
using namespace std;

main(int argc, char* argv[]){            // type your name as command line argument
  /* Read command line argument */
  if (argv[1]!=NULL){
    std::cout << "Hello " << argv[1] << "\n";
  }
  /* Read standard input */
  double weight, height;
  std::cout << "This is a BMI Calculator\n";
  std::cout << "Enter your weight (kg): ";
  std::cin >> weight;
  std::cout << "Enter your height (m): ";
  std::cin >> height;
  std::cout<< "Your BMI: " << weight/(height*height) << "\n";
}
