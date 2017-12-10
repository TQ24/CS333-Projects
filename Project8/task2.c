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

/* timing function */
 double get_time_sec(){
   struct timeval t;
   struct timezone tzp;
   gettimeofday(&t, &tzp);
   return t.tv_sec + t.tv_usec*1e-6;
 }
