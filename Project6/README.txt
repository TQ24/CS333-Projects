CS333 - Project #6 - README
Tracy Quan

Run and build configuration for C:
windows 10

Directory Layout:
Project6/
|
|  |
|  |__/wordcount.c
|  |__/wordcount.exe
|  |__/wctest.txt
|
|
|__/C++/
|  |
|  |__/file.txt
|  |__/Task1-1.cpp
|  |__/Task1-1.exe
|  |__/Task1-2.cpp
|  |__/Task1-2.exe
|  |__/Task2.cpp
|  |__/Task2.exe
|  |__/Task2-2.cpp
|  |__/Task2-2.exe
|  |__/Task2-3.cpp
|  |__/Task2-3.exe
|  |__/test.dat
|  |__/wctest.txt
|  |__/wordcounter.cpp
|  |__/wordcounter.exe
|
|__/JavaScript/
|  |
|  |__/Task1-1.html
|  |__/Task1-2.js
|  |__/Task2.js
|  |__/Task2-2.js
|  |__/test.pdf
|  |__/test.txt
|  |__/wctest.txt
|  |__/wordcounter.js
|
|__/Ruby/
|  |__/Task1-1.rb
|  |__/Task1-2.rb

------------------- PART 1 FILE I/O AND STRING IN C ---------------------------

Summary: The purpose of this part is to let you have some experience on File I/O
in the C language. You are expected to implement a word counter that is able to
count the number of occurrences of every word in a text file.

-- Compile:
gcc -o wordcount wordcount.c

-- Run:
wordcount wctest.txt

-- Output:
the
17
of
7
and
6
was
5
in
4
with
4
a
3
windows
3
broken
2
but
2
portion
2
had
2
were
2
central
2
up
2
wings
2
been
2
claws
1
crab
1
thrown
1

------------- PART 2 FUNCTIONS AND FILE I/O IN SELECTED LANGUAGE ---------------

------------- JavaScript -------------
Task1: File I/O in JavaScript
Task2: Functions in JavaScript
Task3: Word counter

Please see my wiki page.

Operations:
- Open Task1-1.html in a web browser
- Run in command line: node Task1-2.js
- Run in command line: node Task2.js
- Run in command line: node Task2-2.js
- Run in command line: node wordcounter.js

------------- C++ -------------

Please see my wiki page.

Task1: File I/O in C++
-- Compile:
g++ -o Task1-1 Task1-1.cpp
-- Run:
Task1-1 <your name>
-- Compile:
g++ -o Task1-2 Task1-2.cpp
-- Run:
Task1-2

Task2: Functions in C++
-- Compile:
g++ -o Task2 Task2.cpp
-- Run:
Task2
-- Compile:
g++ -o Task2-2 Task2-2.cpp
-- Run:
Task2-2
-- Compile:
g++ -o Task2-3 Task2-3.cpp
-- Run:
Task2-3

Task3: Word counter
-- Compile:
g++ -o wordcounter wordcounter.cpp
-- Run:
wordcounter wctest.text


--------------- EXTENSIONS -------------------------------

------ Undertake one or more tasks for a third language --------

------ RUBY --------
Please see my wiki page.
1. Create a file and write to it. Read from a file
   - Command line: Ruby Task1-1.rb      (This is the command on windows)
2. Read user's input
   - Command line: Ruby Task1-2.rb
3. Read and download contents from internet(wiki)
   - Command line: Ruby Task1-3.rb
4. Pass unknown number of arguments to a FUNCTIONS
   - Command line: Ruby Task2.rb

-------------- Make your word conter more robust so that -----------------------
------it is able to handle invalid command-line inputs and invalid files.-------

In wordcount.c, I checked the number of arguments in command line and error checkd
the file pointer.

In wordcounter.cpp, I also handled invalid command-line inputs and invalid files.
