# CS333
# Project 8
# Part2: Task2
# Parallel sorting in Python


from multiprocessing import Pool
import time
import random
import sys
import random

def merge(left, right):
	if not len(left) or not len(right):
		return left or right

	result = []
	i, j = 0, 0
	while (len(result) < len(left) + len(right)):
		if left[i] < right[j]:
			result.append(left[i])
			i+= 1
		else:
			result.append(right[j])
			j+= 1
		if i == len(left) or j == len(right):
			result.extend(left[i:] or right[j:])
			break

	return result

def mergesort(list):
	if len(list) < 2:
		return list

	middle = len(list)/2
	left = mergesort(list[:middle])
	right = mergesort(list[middle:])

	return merge(left, right)

def merge_2(arr):
    a, b = arr
    return merge(a, b)

def mergeSortParallel(array, thread_level):
    # number of threads
    threads = 2**thread_level
    # assign clips of the array to threads
    rangemark = []
    for i in range(threads+1):
        rangemark.append(i*len(array)/threads)
    args = [array[rangemark[i]:rangemark[i+1]] for i in range(threads)]
    # A pool object controls a pool of workers
    pool = Pool(processes = threads)
    # pool.map() essentially applies a function to each element
    sortedsublists = pool.map(mergesort, args)
    while len(sortedsublists)>1:
        args = [(sortedsublists[i], sortedsublists[i+1]) for i in range(0, len(sortedsublists),2)]
        sortedsublists = pool.map(merge_2, args)
    return sortedsublists[0]

def main():
    array_size_list = [1000, 10000, 100000, 1000000]
    for array_size in array_size_list:
        array_copy = [random.random() for x in range (array_size)]
        # make sure we have two same list
        array = list(array_copy)

        print "Array size: ", array_size, " ---"
        #begin time
        t1 = time.time()
        array = mergesort(array)
        t2 = time.time()
        delta_t = t2 - t1
        print "Total time (Sequential):", delta_t

        array = list(array_copy)
        t1 = time.time()
        thread_level = 3
        array = mergeSortParallel(array, thread_level)
        t2 = time.time();
        delta_t = t2-t1
        print "Total time (Parallel):", delta_t

if __name__=='__main__':
    main()
