/* CS333
Project1
Task3
Write a program that repeatedly allocates a small amount of memory.

Tracy Quan
09/16/2017
*/

#include <stdio.h>
#include <stdlib.h>

// repeatedly allocates a small amount of memory
int main(int arg, char *argv[]){
  int *k ;
  for (int i = 0; i < 1000000000; i++){
    k = (int *)malloc( 10 * sizeof(int) );
    free(k);
  }

  return 0;
}
