#include <thread>
#include <iostream>
using namespace std;

// this thread doesn't represent any thread of execution
// thread t_empty;

// initializing thread with a function
void threadFunc(){
  std::cout << "Welcome to Multithreading" <<endl;
}

int main(){
  //pass a function to threads
  thread funcTest1(threadFunc);
  // this function returns only after all the threds are terminated
  funcTest1.join();
}
