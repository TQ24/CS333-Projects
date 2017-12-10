/* CS333 Project 8 (Last Project!)
 * Tracy Quan
 * 12/7/2017
 *
 * Part1
 * Task1: Write a function that sorts an array.
 * Use parallelism to reduce the computation time.
 * You can use sort functions from the standard library, like qsort in C, or write your own from scratch.
 * Divide the task into N parts for N threads.
 */

#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define ARRAY_SIZE 1000000    // the size of array
#define THREAD_LEVEL 3

/* Structure threadInfo */
struct threadInfo{
  int id;
  double *array;
  double *temp;
  int low;  // lowest index
  int high; // highest index
  int level;
} ;

/* Timing function */
double get_time_sec(){
  struct timeval t;
  struct timezone tzp;
  gettimeofday(&t, &tzp);
  return t.tv_sec + t.tv_usec*1e-6;
}

/* Mergesort */
void merge(double a[], int low, int mid, int high){
  double b[1000];
  int i=low, j=mid+1, k=0;

  while (i<=mid && j<=high){
    if (a[i]<=a[j]){
      b[k++]=a[i++];
    }
    else{
      b[k++]=a[j++];
    }
  }
  while (i<=mid){
    b[k++]=a[i++];
  }
  while (j<=high){
    b[k++]=a[j++];
  }
  k--;
  while (k>=0){
    a[low+k]=b[k];
    k--;
  }
}

void myMergesort(double a[], int low, int high){
  if (low<high){
    int m = (high+low)/2;
    myMergesort(a, low, m);
    myMergesort(a, m+1, high);
    merge(a, low, m, high);
  }
}

void *sort_parallel(void *arg){
  int mid, i;
  void *status;
  struct threadInfo *ti;
  ti = (struct threadInfo *)arg;

  if (ti->level <=0 || ti->low == ti->high){
    myMergesort(ti->array, ti->low, ti->high);
    pthread_exit(NULL);
  }

  /* create threads for the left and right sides */
  struct threadInfo ti_array[2];
  mid = (ti->low + ti->high)/2;
  for (i = 0; i<2; i++){
    ti_array[i].array = ti->array;
    ti_array[i].level = ti->level-1;
  }
  ti_array[0].low = ti->low;
  ti_array[0].high = mid;
  ti_array[1].low = mid+1;
  ti_array[1].high = ti->high;

  /* initialize the threads */
  pthread_t thread[2];
  for (i=0; i<2; i++){
    pthread_create(&thread[i], NULL, sort_parallel, (void *)&ti_array[i]);
  }

  /* join the left and right threads and merge */
  for (i=0; i<2; i++){
    pthread_join(thread[i], NULL);
  }
  merge(ti->array, ti->low, mid, ti->high);
  pthread_exit(NULL);
}

/* parallel mergesort
 * control threads
 */
void parallelMergesort(double array[], int size, int tlevel){
  double *temp = (double *)malloc(size*sizeof(double));
  // initialize the thread
  struct threadInfo ti;
  ti.id = 1;
  ti.array = array;
  ti.low = 0;
  ti.high = size-1;
  ti.level = tlevel;

  pthread_t topThread;
  pthread_create(&topThread, NULL, sort_parallel, (void *)&ti);
  pthread_join(topThread, NULL);
  free(temp);
}


int isSorted(double array[], int size){
  int i;
  for (i=0; i<size; i++){
    if (array[i]<array[i-1]){
      return 0;
    }
  }
  return 1;
}

int main(){
  double t1, t2, delta_ts, delta_tp, diff;
  int i;

  srand(time(NULL));  // create random
  int array_size = ARRAY_SIZE;

  /* create two array for sequential and parallel respectively */
  double *array = (double *)malloc(array_size*sizeof(double));
  double *array_copy = (double *)malloc(array_size*sizeof(double));

  /* assign random value between 0 and 1 to the array */
  for (i=0; i<array_size; i++){
    array[i] = (double)rand()/RAND_MAX;
  }

  /* make sure array and array copy are the same */
  memcpy(array_copy, array, array_size*sizeof(double));

  /* ---------- Sequential Mergesort --------------*/
  t1 = get_time_sec();
  myMergesort(array, 0, array_size-1);
  t2 = get_time_sec();
  delta_ts = t2 - t1;
  if (!isSorted(array, array_size)){
    printf("The array is NOT sorted!");
  }
  else{
    printf("Total Time (Sequential): %f", delta_ts);
  }

  /* ------------ Parallel Mergesort -------------*/
  memcpy(array, array_copy, array_size*sizeof(double));
  t1 = get_time_sec();
  parallelMergesort(array, array_size, THREAD_LEVEL);
  t2 = get_time_sec();
  delta_tp = t2 - t1;
  if (!isSorted(array, array_size)){
    printf("The array is NOT sorted!");
  }
  else{
    printf("Total Time (Sequential): %f", delta_ts);
  }
}
