/* Project1
   Extension4-1: What other kinds of run-time errors can you generate with very simple C programs?

   Tracy Quan
   9/18/2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int main(int arg, char *argv[]){
  int num1 = 2147483647;
  int num2 = 2147483647;
  int num3;
  num3 = num1+num2;
  printf("%d",num3);
  return 0;
}
