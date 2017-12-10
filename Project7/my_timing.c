#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * my_timing.c
 * Return the time in seconds
 */

double get_time_sec(){
  struct timeval t;
  struct timezone tzp;
  gettimeofday(&t, &tzp);
  return t.tv_sec + t.tv_usec*1e-6;
}

double test_time1(unsigned int size, unsigned int times){
  double t1, t2, result, sum, avg;
  int i, j;
  sum = 0;
  for (i = 0; i < times; i++){
    t1 = get_time_sec();
    for (j = 0; j < 5000; j++){
      free(malloc(size));
    }
    t2 = get_time_sec();
    result = t2 - t1;
    sum = sum + result;
  }
  avg = sum/times;
  return avg;
}

// see if the execution time changes as the time of allocation and deallocation grows
void test_time2(unsigned int size, unsigned int times){
  static double lst[10000];
  double t1, t2, result,sum;
  sum = 0;
  int i, j, k;
  for (i = 0; i < times; i++){
    t1 = get_time_sec();
    for (j = 0; j < 1000; j++){
      free(malloc(size));
    }
    t2 = get_time_sec();
    sum = sum+t2-t1;
    lst[i] = t2 - t1;
  }
  printf("Sum of time: %f\n", sum );
  printf("%s\n", "First ten execution time of allocating the given amount of memory 1000 times:\n");
  if (times>=10){
    for (k = 0; k < 10; k++){
      printf("%f\n", lst[k]);
    }
  }
  else{
    for (k = 0; k < times; k++){
      printf("%f\n", lst[k]);
    }
  }
}

// compare with test_time2()
// see if free() function affect execution time
void test_time3(unsigned int size, unsigned int times){
  double t1, t2, result,sum;
  sum = 0;
  int i, j, k;
  for (i = 0; i < times; i++){
    for (j = 0; j < 1000; j++){
      t1 = get_time_sec();
      char *ptr;
      ptr=malloc(size);
      t2 = get_time_sec();
      sum = sum+t2-t1;
      free(ptr);
    }
  }
  printf("Sum of time: %f\n", sum );

}

int main(){
  unsigned int SMALL, MEDIUM, LARGE;
  LARGE = 4e8;
  MEDIUM = 6e6;
  SMALL = 6e3;
  printf("%s\n", "-----------------THIS PROGRAM TAKES REALLY LONG TIME---------------------\n");
  printf("%s\n", "--------------------- PART 1 --------------------------\n");
  printf("Average total time taken by CPU to allocate LARGE memory 1000 times:  %f\n", test_time1(LARGE, 10));
  printf("Average total time taken by CPU to allocate MEDIUM memory 1000 times:  %f\n", test_time1(MEDIUM, 10));
  printf("Average total time taken by CPU to allocate SMALL memory 1000 times:  %f\n", test_time1(SMALL, 10));
  printf("%s\n", "--------------------- PART 2 --------------------------\n");
  printf("%s\n", "test_time2-----------\n");
  test_time2(MEDIUM, 10);
  printf("%s\n", "\ntest_time3 (without freeing the memory)----------\n");
  test_time3(MEDIUM, 10);
}
