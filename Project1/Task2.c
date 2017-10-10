/* CS333
Project1
Task2
Write a infinite loop to see how much memory we can access.

Tracy Quan
09/15/2017
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  int i = 24;
  long l = 123456;
  float f = 2.4;
  double d = 0.8;
  unsigned char *uc;

  //This is for loop with no stopping condition in order to see how much memory we can access.
  uc = (unsigned char *)&(uc);
  printf("Address: %p\n", uc);
  for (int x=0; x!=-1; x++) {
    printf("\nAt Index %d    ", x);
    printf("At Address %p    ", &uc[x]);
    printf("The Value is %d",uc[x]);
  }

  printf("\n");
  return 0;

}
