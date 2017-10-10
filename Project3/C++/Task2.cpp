/* Project3 Task2
 * Tracy Quan
 *
 *
 * C++
 * Task2:Write an example program in each language that executes a binary search
 * on a list or array of numbers.
 */

#include<stdio.h>

int binarySearch(int arr[], int first_index, int last_index, int target){
  while (first_index<=last_index){
    int medium = first_index + (last_index - first_index)/2;
    if (arr[medium]==target){
      return medium;
    }
    if (arr[medium]<target){
      first_index = medium + 1;
    }
    else{
      last_index = medium - 1;
    }
  }
  return -1;     //return -1 if the target not found
}

int main(){
  int arr[] = {2,4,8,16,32,64,128,256};
  int size = sizeof(arr)/sizeof(arr[0]);
  int target = 8;
  int result = binarySearch(arr, 0, size-1, target);
  if (result == 1){
    printf("Taget not found");
  }
  printf("\nTarget is present at index %d\n\n\n", result);
  return 0;
}
