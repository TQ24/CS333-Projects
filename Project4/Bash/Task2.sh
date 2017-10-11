#!/bin/Bash
# CS333 Project4
# Part II - Bash
# Task2

# assign a function to a variable
function date {
  year=2017
  month=October
  day=9
  date="Today is $month $day, $year"
  echo $date
}

variable=$(date)
echo $variable

# pass a parameter to a function
function square() {
  sq=$(($1*$1))   # $1 indicates the first parameter
  echo $sq
}
square 8          # 8 here is the first parameter of function square
first=$(square 8)

# pass the return value of a function to a function as the parameter
square $first
