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

/* --------------------- MergeSort sequential ---------------------*/
void merge(double array[], double temp[], int low, int mid, int high){
  int i_a = low, i_b = mid+1, i = low;
  while (i_a<=mid && i_b<=high){
    if (array[i_a]<=array[i_b]){
      temp[i]=array[i_a];
      i_a++;
    }
    else{
      temp[i]=array[i_b];
      i_b++;
    }
    i++;
  }

  if (i_a>mid){
    memcpy(&temp[i],&array[i_b], (high - i_b + 1)*sizeof(double));
  }
  else{
    memcpy(&temp[i],&array[i_a],(mid-i_a+1)*sizeof(double));
  }
  memcpy(&array[low],&temp[low],(high-low+1)*sizeof(double));
}

/* Merge two subarrays together */
void partition(double array[],double temp[], int low, int high){
  if (low==high){
    return;
  }
  int mid = (low+high)/2;
  partition(array, temp, low, mid);
  partition(array, temp, mid+1, high);
  merge(array, temp, low, mid, high);
}

/* The final mergesort (THE ONE WE ACTUALLY CALL) */
void myMergesort(double array[], int size){
  double *temp = (double *)malloc(size*sizeof(double));
  partition(array, temp, 0, size-1);
  free(temp);
}


/* --------------------- MergeSort Parallel ---------------------*/
void *parallelMergesort(void *arg){
  int mid, i;
  void *status;
  struct threadInfo *ti;
  ti = (struct threadInfo *)arg;

  if (ti->level<0 || ti->low==ti->high){
    partition(ti->array, ti->temp, ti->low, ti->high);
    pthread_exit(NULL);
  }

  struct threadInfo ti_array[2];
  mid = (ti->low + ti->high)/2;
  /* create two threads to sort the left and right subarrays respectively */
  for (i=0; i<2; i++){
    ti_array[i].array = ti->array;
    ti_array[i].temp = ti->temp;
    ti_array[i].level = ti->level-1;
  }
  ti_array[0].low = ti->low;
  ti_array[0].high = mid;
  ti_array[1].low = mid+1;
  ti_array[1].high = ti->high;
  /* initialize the thread */
  pthread_t threads[2];
  for (i = 0; i<2; i++){
    pthread_create(&threads[i], NULL, parallelMergesort, (void *) &ti_array[i]);
  }
  for (i=0; i<2; i++){
    pthread_join(threads[i], NULL);
  }
  /* merge and resort */
  merge(ti->array, ti->temp, ti->low, mid, ti->high);
  /* quit */
  pthread_exit(NULL);
}

/* Use 4 threads. (It would be better if I change number of thread into a parameter) */
void *parallelMergesort_4(void *arg){
  int mid, quatr, i;
  void *status;
  struct threadInfo *ti;
  ti = (struct threadInfo *)arg;

  if (ti->level<0 || ti->low==ti->high){
    partition(ti->array, ti->temp, ti->low, ti->high);
    pthread_exit(NULL);
  }

  struct threadInfo ti_array[4];
  mid = (ti->low + ti->high)/2;
  quatr = mid/2;
  /* create four threads to sort the left and right subarrays respectively */
  for (i=0; i<4; i++){
    ti_array[i].array = ti->array;
    ti_array[i].temp = ti->temp;
    ti_array[i].level = ti->level-1;
  }
  ti_array[0].low = ti->low;
  ti_array[0].high = quatr;
  ti_array[1].low = quatr+1;
  ti_array[1].high = mid;
  ti_array[2].low = mid+1;
  ti_array[2].high = mid+quatr;
  ti_array[3].low = mid+quatr+1;
  ti_array[3].high = ti->high;
  /* initialize the thread */
  pthread_t threads[4];
  for (i = 0; i<2; i++){
    pthread_create(&threads[i], NULL, parallelMergesort, (void *) &ti_array[i]);
  }
  for (i=0; i<4; i++){
    pthread_join(threads[i], NULL);
  }
  /* merge and resort */
  merge(ti->array, ti->temp, ti->low, mid, ti->high);
  /* quit */
  pthread_exit(NULL);
}

void myParallelMergesort(double array[], int size, int threadlevel){
  double *temp = (double *)malloc(size*sizeof(double));
  /* initialize thread struct */
  struct threadInfo ti;
  ti.array = array;
  ti.temp = temp;
  ti.low = 0;
  ti.high = size-1;
  ti.level = threadlevel;
  /* top-level thread */
  pthread_t topThread;
  pthread_create(&topThread, NULL, parallelMergesort, (void *)&ti);
  /* join the thread */
  pthread_join(topThread, NULL);
  /* free temp array */
  free(temp);
}

/* Use 4 threads. (It would be better if I change number of thread into a parameter) */
void myParallelMergesort_4(double array[], int size, int threadlevel){
  double *temp = (double *)malloc(size*sizeof(double));
  /* initialize thread struct */
  struct threadInfo ti;
  ti.array = array;
  ti.temp = temp;
  ti.low = 0;
  ti.high = size-1;
  ti.level = threadlevel;
  /* top-level thread */
  pthread_t topThread;
  pthread_create(&topThread, NULL, parallelMergesort_4, (void *)&ti);
  /* join the thread */
  pthread_join(topThread, NULL);
  /* free temp array */
  free(temp);
}

/* comparator func for built-in qsort */
int cmpfunc(const void *a, const void *b){
  const double *db_a = (const double *) a;
  const double *db_b = (const double *) b;
  return (*db_a>*db_b)-(*db_a<*db_b);
}


/* MAIN FUNCTION */
int main(int argc, char *argv[]){
  double t1, t2, delta_ts, delta_tp, diff;
  int i;

  srand(time(NULL));  // create random
  int array_size = ARRAY_SIZE;  // default array size

  /* take array size from command line if there is an input */
  if (argc==2){
    array_size = atoi(argv[1]);
  }

  /* create two array for sequential and parallel respectively */
  double *array = (double *)malloc(array_size*sizeof(double));
  double *array_copy = (double *)malloc(array_size*sizeof(double));

  /* assign random value between 0 and 1 to the array */
  for (i=0; i<array_size; i++){
    array[i] = (double)rand()/RAND_MAX;
  }

  /* make sure array and array copy are the same */
  memcpy(array_copy, array, array_size*sizeof(double));

  printf("Array Size: %d\n", array_size);

  /* ---------- Sequential Mergesort --------------*/
  t1 = get_time_sec();
  myMergesort(array, array_size);
  t2 = get_time_sec();
  delta_ts = t2 - t1;
  printf("Total Time (Sequential): %f\n", delta_ts);

  /* ------------ Parallel Mergesort - 2 threads -------------*/
  memcpy(array, array_copy, array_size*sizeof(double));
  t1 = get_time_sec();
  myParallelMergesort(array, array_size, THREAD_LEVEL);
  t2 = get_time_sec();
  delta_tp = t2 - t1;
  printf("Total Time (Parallel - 2 threads): %f\n", delta_tp);

  /* ------------ Parallel Mergesort - 4 threads -------------*/
  memcpy(array, array_copy, array_size*sizeof(double));
  t1 = get_time_sec();
  myParallelMergesort_4(array, array_size, 5);
  t2 = get_time_sec();
  delta_tp = t2 - t1;
  printf("Total Time (Parallel - 4 threads): %f\n", delta_tp);

  /* ------------ Built-in Qsort (sequential) -------------*/
  memcpy(array, array_copy, array_size*sizeof(double));
  t1 = get_time_sec();
  qsort(array, array_size, sizeof(double), cmpfunc);
  t2 = get_time_sec();
  delta_ts = t2 - t1;
  printf("Total Time of Sorting 1 time (Built-in qsort): %f\n", delta_ts);

  free(array);
  free(array_copy);
  pthread_exit(NULL);

  return 0;
}
