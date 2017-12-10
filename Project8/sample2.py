# Roxana Gheorghe
# December 12, 2014
# CS333
#Project 8


#Description : sorts an array in parallel, sequentially	 and using the built-in sort method
# and times the methods

from multiprocessing import Pool
import time, random, sys

# create the array, run the sequential sort, run the parallel sort and run the built-in
#sorted method
def main():

 array_size = 500000

 #Want to compare sorting on the same list, so create a copy and
 #populate it with random numbers.
 array_backup = [random.random() for x in range(array_size)]

 #Time sequential mergesort on a copy of original array.
 array = list(array_backup)
 start = time.time() #start time
 array = mergesort(array)
 diff = time.time() - start	 #stop time
 #check if array is sorted
 if not isSorted(array):
 print('Sequential mergesort did not sort the array')

 print('Sequential mergesort took : %f sec' % (diff))

 #Time the parallel mergeSort on a copy of the original array
 array = list(array_backup)
 start = time.time() #start time
 thread_level = 3
 array = mergeSortParallel(array, thread_level)
 diff = time.time() - start #end time
 #check if array is sorted
 if not isSorted(array):
 print('mergeSortParallel did not sort the array.')

 print('Parallel mergesort took : %f sec' % (diff))


 #Time Built-in sorted method.
 array = list(array_backup)
 start = time.time()
 array = sorted(array)
 diff = time.time() - start
 print('Built-in sorted took : %f sec' % (diff))


def merge(left, right):
 """returns a merged and sorted version of the two already-sorted lists."""
 result = []
 left_idx = right_idx = 0
 while left_idx < len(left) and right_idx < len(right):
 if left[left_idx] <= right[right_idx]:
 result.append(left[left_idx])
 left_idx += 1
 else:
 result.append(right[right_idx])
 right_idx += 1
 if left_idx == len(left):
 result.extend(right[right_idx:])
 else:
 result.extend(left[left_idx:])
 return result

def mergesort(array):
 """
 Normal mergesort method; divide array into halves
 and merge them back together when you're done
 """
 if len(array) <= 1:
 return array
 ind = len(array)//2
 return merge(mergesort(array[:ind]), mergesort(array[ind:]))

def mergeHelper(Twothings):
 one,two = Twothings
 return merge(one,two)

def mergeSortParallel(array, thread_level):
 """
 Parallel MergeSort
 """
 threads = 2**thread_level
 #Evenly divide the array indices.
 endpoints=[]
 for i in range(threads+1):
 endpoints.append(i*len(array)/threads)
 #partition the array.
 args = [array[endpoints[i]:endpoints[i+1]] for i in range(threads)]
 #instantiate a Pool of workers
 pool = Pool(processes = threads)
 sortedsublists = pool.map(mergesort, args)
 #i.e., perform mergesort on the first 1/numproc of the array,
 #the second 1/numproc of the array, etc.

 #Now combine the sorted sublists with merge.
 while len(sortedsublists) > 1:
 #get sorted sublist pairs to send to merge
 args = [(sortedsublists[i], sortedsublists[i+1]) \
 for i in range(0, len(sortedsublists), 2)]
 sortedsublists = pool.map(mergeHelper, args)

 #Since we start with numproc a power of two, there will always be an
 #even number of sorted sublists to pair up, until there is only one.

 return sortedsublists[0]

def isSorted(array):
 """
 Return whether the argument array is in non-decreasing order.
 """
 for i in range(1, len(array)):
 if array[i] < array[i-1]:
 return False
 return True

if __name__ == '__main__':
 main()
