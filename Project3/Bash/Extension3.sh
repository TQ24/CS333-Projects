#!/bin/Bash
# Extension3: Binary Search in Bash

binarySearch(){
  array=("$@")    #$@ in a shell script is an array of all arguments given to the script
  last_idx=$((${#array[@]} - 1))   # @ Expands to the positional parameters, starting from one.
  item=${array[last_idx]}
  unset array[last_idx]     #Delete the variable
  end=$((${#array[@]} - 1))
  _start=0
  mid=$(( (_start+end)/2  ))
  while [ $_start -le $end ];do
    if [ ${array[mid]} -eq $item ];then
      echo  $mid 
      exit 1
    elif [ ${array[mid]} -gt $item  ];then
        end=$(( mid  - 1 ))
    else
      _start=$(( mid + 1 ))
    fi
    mid=$(( (_start+end)/2  ))
  done
  echo "-1"

}

ARRAY=(2 4 8 16 32 64)
TARGET=8
binarySearch ${ARRAY[@]} $TARGET
