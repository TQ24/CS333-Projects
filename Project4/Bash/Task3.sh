#!/bin/bash
# CS333 Project4
# Part II - Bash
# Task3 merge sort

# this mergesort function takes two parameters: length of the array and the array
function mergesort(){
  if [[ $1 -ge 2 ]]            #if the length of array is greater than 2
  then
    local mid=$(( $1 / 2 ))   #the midpoint of the array
    local left=( $(mergesort $mid ${@:2:$mid}) )  #the first section of the array
    local right=( $(mergesort $(( $1 - $mid)) ${@:$(( $mid + 2 )):$(( $1 - $mid ))}) )  #the second seciton
    echo $(merge $mid ${left[@]} ${right[@]})
  else
    echo $2                   #if the length of array is smaller than 2,then just return the array
  fi
}

function merge() {
	local first=2                                  #the index of the first element of the left sub array
	local second=$(( $1 + 2 ))                     #the index of the first element of the right sub array
	for i in ${@:2}
	do
		if [[ $first -eq $(( $1 + 2 )) ]]            #compare the current first term of two sub arrays
		then
			echo ${@:$second:1} ; ((second += 1))
		else
			if [[ $second -eq $(( ${#@} + 1 )) ]]
			then
				echo ${@:$first:1} ; ((first += 1))
			else
				if [[ ${@:$first:1} -lt ${@:$second:1} ]]
				then
					echo ${@:$first:1} ; ((first += 1))
				else
					echo ${@:$second:1} ; ((second += 1))
				fi
			fi
		fi
	done
}

array1=(10 9 8 7 6 0 5 4 3 2 1)
echo The original array: ${array1[@]}
echo The sorted array: $(mergesort 11 ${array1[@]})
