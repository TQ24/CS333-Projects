#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main () {
   clock_t start_t, end_t, total_t;
   int i = 0;
   start_t = clock();
   for (i; i<1000; i++){
     free(malloc(10000));
   }
   end_t = clock();
   total_t = (end_t - start_t)/CLOCKS_PER_SEC;
   printf("Total time taken by CPU: %.10f\n", total_t);
}
