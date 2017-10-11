#!/bin/Bash
# CS333 Project4
# Part II - Bash
# Task1

# conditional statements: if-else
echo ------ if-else-fi ------
school=Colby
function conditional_stat {
  if [ $school == Colby ]
  then
    echo Go Mules!
  fi
}
conditional_stat

# nested if statements
echo ------ nested if statements ------
number=24
function nestedif {
  if [ $number -gt 20 ]
  then
    echo $number is larger than 20
    if (( $number % 2 == 0 ))
    then
      echo $number is an even number
    fi
  fi
}
nestedif

# Loops statements: for loop
echo ------ for loop ------
names='Andy Bill Cole David'
function namelist {
  for name in $names
  do
    echo $name
  done
}
namelist

# Loops statements: while loop
echo ------ while loop ------
start=1
function countup {
  while [ $start -le 10 ]
  do
    echo $start
    ((start++))
  done
}
countup

#case statements
echo ------ case statements ------
trafficlight=red
function case_stat {
  case $trafficlight in
    red)
      echo traffic light: $trafficlight
      echo STOP
      ;;
    yellow)
      echo traffic light: $trafficlight
      echo SLOW DOWN
      ;;
    green)
      echo traffic light: $trafficlight
      echo GO
      ;;
  esac
}
case_stat
trafficlight=green
case_stat
trafficlight=yellow
case_stat
