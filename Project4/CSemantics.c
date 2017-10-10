/* Project 4
 * Part I: C Semantics
 * Tracy Quan
 * 
 * Given an array of random integers, sort the array in a way that the even numbers appear first and the odd 
 * numbers appear later. The even numbers should be sorted in descending order and the odd numbers should be 
 * sorted in ascending order.
 */

#include <stdio.h>
#include <stdlib.h>

/* the comparator function used in qsort */
int comparator(const void *a, const void *b){
	int *p = (int *)a;
	int *q = (int *)b;
	if (p == q){	//if p equals q
		return 0;
	}
	else if ( (*p % 2 == 0) && (*q%2 != 0) ){		//if p is even and q is odd
		return -1;
	}
	else if ( (*p%2 != 0) && (*q%2 == 0) ){		//if p is odd and q is even
		return 1;
	}
	else if ( (*p%2 == 0) && (*q%2 == 0) ){		//if p and q are both even
		if (*p>*q){
			return -1;
		}
		else if (*p==*q){
			return 0;
		}
		return 1;
	}
	else if ( (*p%2 != 0) && (*q%2 != 0) ){		//if p and q are both odd
		if (*p<*q){
			return -1;
		}
		else if (*p==*q){
			return 0;
		}
		return 1;
	}
	return 24;									//does not do anything
}

int main (int argc, char **argv){
	printf("\n");
	int ary[] = {10,11,1,8,9,0,13,4,2,7,6,3,5,12};

	int size = sizeof(ary)/sizeof(int);

	qsort((void *) ary, size, sizeof(int), comparator);

	printf("The sorted array is: ");
	for (int i = 0; i<size; i++){
		printf("%d  ",ary[i]);
	}
	printf("\n\n");

	return 0;
}