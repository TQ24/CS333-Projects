/**
 * CS333 HW 10 Question 2.
 *
 * Compile with
 *   gcc -pthread -o hw10_question2 hw10_question2.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 16

int sum = 0;
pthread_mutex_t lock;

typedef struct {
  int id;
  int my_num;
} threadInfo;


void *thread_sum10_A( void *arg ) {
  threadInfo *ti = (threadInfo *)arg;
  if (sum + ti->my_num <= 10) {
    sum += ti->my_num;
  }
  pthread_exit(NULL);
}

void *thread_sum10_B( void *arg ) {
  threadInfo *ti = (threadInfo *)arg;
  if (sum + ti->my_num <= 10) {
    pthread_mutex_lock( &lock );
    sum += ti->my_num;
    pthread_mutex_unlock( &lock );
  }
  pthread_exit(NULL);
}

// This is the main thread code for question 2. It will be called in a
// loop so that we run it enough times for things to go wrong.
int question_2_main() {
  threadInfo ti[NUM_THREADS];
  pthread_t thread[NUM_THREADS];
  int i;

  for(i=0;i<NUM_THREADS;i++) {
    ti[i].my_num = (i%3)+1;
    ti[i].id = i; // tell the thread its ID
  }

  // Initialize the global variable.
  sum = 0;

  // initialize the mutex lock
  pthread_mutex_init(&lock,NULL);

  // call the threads
  // To investigate the effects of the different thread codes, switch out
  // thread_A, thread_B, and thread_C as the input to pthread_create
  for(i=0;i<NUM_THREADS;i++) {
    pthread_create(&(thread[i]), NULL, thread_sum10_B, &(ti[i]) );
  }

  // join the threads (this is where we wait)
  for(i=0;i<NUM_THREADS;i++) {
    pthread_join( thread[i], NULL );
  }

  // destroy the mutex lock (we are done with it)
  pthread_mutex_destroy(&lock);

  if (sum != 10)
    printf( "the sum isn't 10, it is %d\n", sum );

  return 0;
}


int main(int argc, char *argv[]) {
    int i;
    for (i=0; i < 10000; i++)
        question_2_main();
    return 0;
}
