/*Project1
Extension1 : generate a bus error(Version1)

Tracy Quan
Sep 18,2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>


//use a processor instruction with an address that does not satisfy its alignment requirements.
int main(int arg, char *argv[]){
  char *p = "Colby";
  char *q = "Davis";
  strcpy(p,q);
  //raise(SIGBUS);
  return 0;
}
