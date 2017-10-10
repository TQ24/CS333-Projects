/*Project1
Extension1 : generate a bus error(Version2)

Tracy Quan
Sep 18,2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>


int main(int arg, char *argv[]){
  raise(SIGBUS);
  return 0;
}
