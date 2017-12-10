/* CS333
 * Project 7
 *
 * Part2
 * C++
 * Memory allocation and deallocation
 */

#include <iostream>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

double get_time_sec(){
  struct timeval t;
  struct timezone tzp;
  gettimeofday(&t, &tzp);
  return t.tv_sec + t.tv_usec*1e-6;
}

double time_test(int size){
  double lst[20];
  double t1, t2, result, sum;
  int i, j, k;
  sum = 0;
  for (i=0; i<20; i++){
    t1 = get_time_sec();
    for (j=0; j<100000; j++){
      char *p = new char[size];
      delete p;
      p = 0;
    }
    t2 = get_time_sec();
    result = t2-t1;
    sum = sum + result;
    lst[i]=result;
  }
  cout<<"Array size: "<<size<<" -----------\n";
  cout<<"Sum: "<<sum<<"\n";
  cout<<"Each time: \n";
  for (k=0; k<20; k++){
    cout<<lst[k]<<"\n";
  }
}

int main(){
  cout<<"This program takes fairly long time!\n";
  time_test(10000);
  time_test(100000);
  time_test(1000000);
  time_test(10000000);
}
