/* CS333 Project 8 (Last Project!)
 * Tracy Quan
 * 12/8/2017
 *
 * Part1
 * Task2: Write a program that reads an image and applies a pixel-wise operator to it.
 * Use parallelism to reduce the computation time. You can use this C-kit as the basis for your C example.
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "ppmIO.h"
 #include <sys/time.h>
 #include <time.h>
 #include <pthread.h>

 #define NUM_THREADS 256   // the number of threads


/* timing function */
 double get_time_sec(){
   struct timeval t;
   struct timezone tzp;
   gettimeofday(&t, &tzp);
   return t.tv_sec + t.tv_usec*1e-6;
 }

/* thread info structure */
typedef struct{
  int id;
  Pixel *pixel;
  int num_pixel;
} threadInfo;

/* recolor image*/
void *change_image(void *arg){
  int i;
  threadInfo *ti = (threadInfo *)arg;
  for (i=0; i<ti->num_pixel; i++){
    ti->pixel[i].r = 128 ? (220 + ti->pixel[i].r)/2 : (30 + ti->pixel[i].r)/2;
    ti->pixel[i].g = 128 ? (220 + ti->pixel[i].g)/2 : (30 + ti->pixel[i].g)/2;
    ti->pixel[i].b = 128 ? (220 + ti->pixel[i].b)/2 : (30 + ti->pixel[i].b)/2;
  }
}

/* main function */
int main(int argc, char *argv[]){
  /* check usage */
  if (argc<2){
    printf("Usage: %s <image filename>\n", argv[0]);
    exit(-1);
  }

  double t1, t2, delta_t;   // Timing
  Pixel *src;   // source image
  int rows, cols, colors;   // image info
  int i, j, num_threads, num_iteration;

  /* read image and check for errors */
  src = ppm_read( &rows, &cols, &colors, argv[1] );
  if (!src){
    printf("Unable to read file %s\n", argv[1]);
    exit(-1);
  }

  num_threads =  NUM_THREADS;
  if (argc==3){
    num_threads = atoi(argv[2]);
  }

/*
  num_iteration = NUM_ITERATION;
  if (argc==4){
    num_iteration = atoi(argv[3])
  }
*/
  /* initialize threads */
  threadInfo ti[num_threads];
  pthread_t thread[num_threads];
  for (i=0; i<num_threads; i++){
    ti[i].id = i;
    ti[i].num_pixel = (rows * cols)/num_threads;
    ti[i].pixel = &(src[i*rows*cols/num_threads]);
  }
  t1 = get_time_sec();
  for (i=0; i<num_threads; i++){
    pthread_create(&(thread[i]), NULL, change_image, &(ti[i]));
  }
  for (i=0; i<num_threads; i++){
    pthread_join(thread[i], NULL);
  }
  t2 = get_time_sec();
  delta_t = t2 - t1;
  printf("Number of Threads: %d\nImage Processing Time: %f\n", num_threads, delta_t);
  ppm_write( src, rows, cols, colors, "bold.ppm" );
  free(src);

  return 0;
}
