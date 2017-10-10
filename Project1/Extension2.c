/*Project1
Extension2 : Find the floating point number in C to which you can add one and get back the same number

Tracy Quan
Sep 18,2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int arg, char *argv[]){
  float stop = 0;
  // keep increase the float by 1
  for (int x = 0; x<100000000; x++){
    stop = stop + 1;
    printf("%f\n",stop);
  }
  return 0;
}
