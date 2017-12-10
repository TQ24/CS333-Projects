/*Roxana Gheorghe
18/11/2014
CS333
Project 8
Description : Sort an array using MergeSort. The array is a random list of size given by the argument (default 1M)
Compute the time of both the sequential mergesort method and of the parallel mergeSort method
 
$ gcc -pthread -std=c99 -o part1 part1.c
$ ./part1 1000000
*/
 
 
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
 
#define ARRAY_SIZE 1000000
#define THREAD_LEVEL 3
 
//for sequential and parallel implementation
void merge(double array[], double back[], int low, int mid, int high);
void partition(double array[], double back[], int low, int high);
void myMergesort(double array[], int size);
int isSorted(double array[], int size);
 
//for parallel implementation
void parallelMergesort(double array[], int size, int tlevel);
void *parallelMergesortHelper(void *threadarg);
 
struct threadInfo{
  double *array;
  double *temp;
  int low;
  int high;
  int level;
} ;
 
 
//for the builtin qsort, for fun:
int compare_doubles (const void *a, const void *b);
 
/*
Main method:
-generate random list
-time sequential mergesort
-time parallel mergesort
*/
int main (int argc, char *argv[])
{
    struct timeval start, end;
    double diff;
 
    srand(time(NULL)); //seed random
 //
    int size = ARRAY_SIZE;
    //check if user specified list size.
    if (argc == 2)
    {
        size = atoi(argv[1]);
    }
// 
    //Want to compare sorting on the same list,
    //so create a copy of it.
    double *array_backup = (double *) malloc(size*sizeof(double));
    double *array = (double *) malloc(size*sizeof(double));
 
    //Populate backup array with random doubles.
    for(int i = 0; i < size; i ++)
    {
        array_backup[i] = 1.0*rand()/RAND_MAX;
    }
 
    //copy backup into array.
    memcpy(array, array_backup, size*sizeof(double));
 
 
 
    //Sequential mergesort, and timing.
    gettimeofday(&start, NULL);
    myMergesort(array, size);
    gettimeofday(&end, NULL);
 
    if (!isSorted(array, size))
    {
        printf("Oops, arrray did not get sorted by mergesort.\n");
    }
 
    //Compute time difference.
    diff = (end.tv_sec  + (end.tv_usec*1e-6))
          - (start.tv_sec + (start.tv_usec*1e-6));
    printf("Sequential mergesort took: %lf sec.\n", diff);
 
 
    //Now, parallel mergesort.
 
    //copy list.
    memcpy(array, array_backup, size*sizeof(double));
 
    gettimeofday(&start, NULL);
    parallelMergesort(array, size, THREAD_LEVEL);
    gettimeofday(&end, NULL);
 
    if (!isSorted(array, size))
    {
        printf("Oops, array did not get sorted by parallelMergesort.\n");
    }
 
    //Compute time difference.
    diff = (end.tv_sec  + (end.tv_usec*1e-6))
          - (start.tv_sec + (start.tv_usec*1e-6));
    printf("Parallel mergesort took: %lf sec.\n", diff);
 
 
 
    //compare it to qsort builtin
    memcpy(array, array_backup, size*sizeof(double));
    gettimeofday(&start, NULL);
    qsort(array, size, sizeof(double), compare_doubles);
    gettimeofday(&end, NULL);
 
    if (!isSorted(array, size))
    {
        printf("Oops, array did not get sorted by qsort.\n");
    }
 
    //Compute time difference.
    diff = (end.tv_sec  + (end.tv_usec*1e-6))
          - (start.tv_sec + (start.tv_usec*1e-6));
    printf("Built-in qsort took: %lf sec.\n", diff);
 
 
 
    free(array);
    free(array_backup);
    pthread_exit(NULL);
}
 
 
//top level sequential mergesort
void myMergesort(double array[], int size)
{
    double *temp = (double *) malloc(size*sizeof(double));
    partition(array, temp, 0, size-1);
    free(temp);
}
 
//the actual C mergesort method, with back list to avoid
//NlogN memory (2N instead).
void partition(double array[], double temp[], int low, int high)
{
    if (low == high) return;
    int mid = (low + high)/2;
    partition(array, temp, low, mid);
    partition(array, temp, mid+1, high);
    merge(array, temp, low, mid, high);
}
 
//merge the elements from the sorted subarrays in [low, mid] and (mid, high]
void merge(double array[], double temp[], int low, int mid, int high)
{
    int ai = low, bi = mid + 1, i = low;
    while (ai <= mid && bi <= high)
    {
        if (array[ai] <= array[bi])
        {
            temp[i] = array[ai];
            ai ++;
        }else
        {
            temp[i] = array[bi];
            bi ++;
        }
        i ++;
    }
    if (ai > mid)
    {
        memcpy(&temp[i], &array[bi], (high-bi+1)*sizeof(double));
    }else
    {
        memcpy(&temp[i], &array[ai], (mid-ai+1)*sizeof(double));
    }
    memcpy(&array[low], &temp[low], (high-low+1)*sizeof(double));
}
 
//check if the elements of array are in non-decreasing order.
int isSorted(double array[], int size)
{
    for (int i = 1; i < size; i ++)
    {
        if (array[i] < array[i-1])
        {
            printf("%e < %e\n", array[i], array[i-1]);
            return 0;
        }
    }
    return 1;
}
 
 
/*
parallel mergesort top level
instantiate parallelMergesortHelper thread
*/
void parallelMergesort(double array[], int size, int tlevel)
{
    double *temp = (double *) malloc(size*sizeof(double));
 
 
    //initialize thread struct.
    struct threadInfo ti;
    ti.array = array;
    ti.temp = temp;
    ti.low = 0;
    ti.high = size - 1;
    ti.level = tlevel;
 
    //The top-level thread.
    pthread_t theThread;
    pthread_create(&theThread, NULL, parallelMergesortHelper,
                        (void *) &ti);
 
 
    //Now join the thread (wait, as joining blocks) and quit.
    pthread_join(theThread, NULL);
 
 
    free(temp);
 
}
 
/*
parallelMergesortHelper
-if the level is still > 0, then make
parallelMergesortHelper threads to solve the left and
right-hand sides, then merge results after joining
 and quit.
*/
void *parallelMergesortHelper(void *arg)
{
    int mid, t;
    void *status;
 
    struct threadInfo *ti;
    ti = (struct threadInfo *) arg;
 
 
    if (ti->level <= 0 || ti->low == ti->high)
    {
        //We have plenty of threads, finish with sequential.
        partition(ti->array, ti->temp,
                        ti->low, ti->high);
        pthread_exit(NULL);
    }
 
 
    //At this point, we will create threads for the
    //left and right sides.  Must create their data args.
    struct threadInfo ti_array[2];
    mid = (ti->low + ti->high)/2;
 
    for (t = 0; t < 2; t ++)
    {
        ti_array[t].array = ti->array;
        ti_array[t].temp = ti->temp;
        ti_array[t].level = ti->level - 1;
    }
    ti_array[0].low = ti->low;
    ti_array[0].high = mid;
    ti_array[1].low = mid+1;
    ti_array[1].high = ti->high;
 
    //Now, instantiate the threads.
    pthread_t threads[2];
    for (t = 0; t < 2; t ++)
    {
        pthread_create(&threads[t], NULL, parallelMergesortHelper,
                            (void *) &ti_array[t]);
 
    }
 
 
    //Now, join the left and right threads and merge.
    for (t = 0; t < 2; t ++)
    {
        pthread_join(threads[t], NULL);
 
    }
 
    //Call the sequential merge now that the left and right
    //sides are sorted.
    merge(ti->array, ti->temp, ti->low, mid, ti->high);
 
    pthread_exit(NULL);
}
 
//for the built-in qsort comparator
int compare_doubles (const void *a, const void *b)
{
    const double *da = (const double *) a;
    const double *db = (const double *) b;
 
    return (*da > *db) - (*da < *db);
}
