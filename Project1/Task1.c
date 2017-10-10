/* CS333
My first #C program
Project 1
Task 1
Memory Access: We declare several variables and then examine how they are stored in memory.

Tracy Quan
09/15/2017
*/

#include <stdio.h>
#include <stdlib.h>

// Memory access
int main(int argc, char *argv[]) {
  char c = 'a';
  short s = 12345;
  int i = 24;
  long l = 123456;
  float f = 2.4;
  double d = 0.8;

  // print out the size of memory that interger i needs and the value in each byte.
  printf("--- Integer i ---");
  unsigned char *ptr;
  ptr = (unsigned char *)&(i);
  printf("\nSize of i = %lu", sizeof(i));
  for (int x = 0; x < sizeof(i); x++){
    printf("\nAt Address %p ", &ptr[x]);
    printf("\nThe value is %d", ptr[x]);
  }

  // print out the size of memory that Character c needs and the value in each byte.
  printf("\n\n--- Character c ---");
  ptr = (unsigned char *)&(c);
  printf("\nSize of c = %lu", sizeof(c));
  for (int x = 0; x < sizeof(c); x++){
    printf("\nAt Address %p ", &ptr[x]);
    printf("\nThe value is %d", ptr[x]);
  }

  // print out the size of memory that Short s needs and the value in each byte.
  printf("\n\n--- Short s ---");
  ptr = (unsigned char *)&(s);
  printf("\nSize of c = %lu", sizeof(s));
  for (int x = 0; x < sizeof(s); x++){
    printf("\nAt Address %p ", &ptr[x]);
    printf("\nThe value is %d", ptr[x]);
  }

  // print out the size of memory that Long l needs and the value in each byte.
  printf("\n\n--- Long l ---");
  ptr = (unsigned char *)&(l);
  printf("\nSize of l = %lu", sizeof(l));
  for (int x = 0; x < sizeof(l); x++){
    printf("\nAt Address %p ", &ptr[x]);
    printf("\nThe value is %d", ptr[x]);
  }

  // print out the size of memory that Float f needs and the value in each byte.
  printf("\n\n--- Float f ---");
  ptr = (unsigned char *)&(f);
  printf("\nSize of f = %lu", sizeof(f));
  for (int x = 0; x < sizeof(f); x++){
    printf("\nAt Address %p ", &ptr[x]);
    printf("\nThe value is %d", ptr[x]);
  }

  // print out the size of memory that Double d needs and the value in each byte.
  printf("\n\n--- Double d ---");
  ptr = (unsigned char *)&(d);
  printf("\nSize of d = %lu", sizeof(d));
  for (int x = 0; x < sizeof(d); x++){
    printf("\nAt Address %p ", &ptr[x]);
    printf("\nThe value is %d", ptr[x]);
  }


  printf("\n");
  return 0;

}
