/* CS333
 * Project 6
 * Part2: File I/O in selected Language
 *
 * Task2: Exploring functions in C++
 * Unknown number of arguments
 */


#include <stdarg.h>
#include <iostream>

int max(int n_args, ...){
  va_list ap;
  va_start(ap, n_args);
  int max = va_arg(ap, int);
  for (int i = 2; i <= n_args; i++){
    int a = va_arg(ap, int);
    if (a>max){
      max = a;
    }
  }
  va_end(ap);
  return max;
}


int main(){
  int m = max(6,2,24,43,5,6,60);
  printf("%d\n", m);
  return 0;
}
