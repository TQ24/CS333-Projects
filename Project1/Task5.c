/* CS333
Project1
Task5
Demonstrate how, by passing a string that is slightly too long to a function,
you can overwrite a decision variable within the function if the function uses
strcpy (and don't forget to include string.h) to copy the parameter to a local
character array of fixed length.

Tracy Quan
09/16/2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int arg, char *argv[]){
  char str[4];
  char str2[] = "Colby";
  //copy a slightly longer string to str;
  strcpy(str, str2);

  int check = 0;
  //check if the memory changed
  if (check == 0){
    printf("safe");
  }
  else{
    printf("hacked");
  }


  return 0;
}
