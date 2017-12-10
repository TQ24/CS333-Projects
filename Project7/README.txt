CS333 - Project #7 - README
Tracy Quan

Run and build configuration for C:
windows 10

Directory Layout:
Project7/
|
|  |
|  |__/my_timing.c
|  |__/my_timing.exe
|  |__/my_timing.h
|
|
|__/C++/
|  |
|  |__/Task1.cpp
|  |__/Task1.exe
|  |__/Task2.cpp
|  |__/Task2.exe
|
|__/JavaScript/
|  |
|  |__/Task1.js
|  |__/Task2.html
|
|__/Ruby/
|  |__/Extension1.rb
|  |__/Extension2.rb

------------------- PART 1 Memory Management in C ---------------------------

Summary: This part is try and estimate the big O complexity and time cost in C.

-- Compile:
gcc -o my_timing my_timing.c

-- Run:
my_timing (This program takes a long time)

-- Output:
-----------------THIS PROGRAM TAKES REALLY LONG TIME---------------------

--------------------- PART 1 --------------------------

Average total time taken by CPU to allocate LARGE memory 1000 times:  6.369714
Average total time taken by CPU to allocate MEDIUM memory 1000 times:  0.109589
Average total time taken by CPU to allocate SMALL memory 1000 times:  0.000000
--------------------- PART 2 --------------------------

test_time2-----------

Sum of time: 0.230351
First ten execution time of allocating the given amount of memory 1000 times:

0.018167
0.015622
0.031254
0.015601
0.021676
0.035648
0.024298
0.015626
0.024687
0.027772

test_time3 (without freeing the memory)----------

Sum of time: 0.109746

---- According to the comparison between test_time2 and test_time3, my result shows
     that it takes longer when we need to free memory for Medium memory size.


------------- PART 2 FUNCTIONS AND FILE I/O IN SELECTED LANGUAGE ---------------

------------- JavaScript -------------
Please see my wiki page.

Operations:
- Task1.js is just a demo, nothing to run
- Open Task1.html in a web browser

------------- C++ -------------
Please see my wiki page.

Task1:
-- Compile:
g++ -o Task1 Task1.cpp
-- Run:
Task1

Task2:
-- Compile:
g++ -o Task2 Task2.cpp
-- Run:
Task2


--------------- EXTENSIONS -------------------------------
1. Describe memory management for a third language.
  -- Ruby (Please see my wiki page)
  Command Line: Ruby Extension1.rb

2. For the memory management example, try writing a functionally equivalent example in C,
explicitly handling the kinds of information required for the memory management system of your chosen language.
  -- For Ruby's memory management example, I wrote a functionally equivalent example in C.
     (Please see my Ruby's wiki page)
     Extension2.rb is just a code demonstration, nothing to run.

  -- For C++'s memory management example, I wrote a functionally equivalent example in C.
      (Please see my C++'s wiki page)

3. Write a compilable haiku on memory management.
   (Please see my wiki page)
