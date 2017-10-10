/* CS333
Project1
Task4
Make a struct that has 3-4 different variables (including some char and short types).
Set up the structure so it should use an odd number of bytes.
Write a program that allocates one of these structures.
Then use the unsigned char * to look at how the memory is laid out.

Tracy Quan
09/16/2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//a structure of student which contains information about name, age, gender, and dorm
struct student {
  char name[7];      // 7 bytes
  short classyear;   // 2 bytes
  char major[18];    // 18 bytes
};

int main (int argc, char *argv[]){
  //initializes st1
  struct student stu1;
  strcpy(stu1.name, "TracyQ");
  stu1.classyear = 2020;
  strcpy(stu1.major, "ComputerScience");

  //print out student1's information
  printf("\n%s: %d, %s", stu1.name,  stu1.classyear, stu1.major);

  unsigned char *ptr;
  ptr = (unsigned char *)&(stu1);
  // print out my expected size of stu1
  printf("\n\nExpected Size: %lu + %lu + %lu = %lu", sizeof(stu1.name), sizeof(stu1.classyear), sizeof(stu1.major), (sizeof(stu1.name)+sizeof(stu1.classyear)+sizeof(stu1.major)));
  // print out the actual size of stu1
  printf("\nActual Size: %lu\n", sizeof(stu1));

  // see how the memory is laid out
  for (int i = 0; i < sizeof(stu1); i++){
    printf("\nAt Address %p   ", &ptr[i]);
    printf("The Value is %d", ptr[i]);
  }

  printf("\n");
  return 0;
}
