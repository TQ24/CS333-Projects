CS333 - Project #1 - README
Tracy Quan

Run and build configuration for C:
OSX El Capitan 10.11.6 - Apple LLVM version 7.3.0 (clang-703.0.31)

C:
  This is the C programming task. There are five tasks in this project, which are
  dealing with data types, memory access, arrays, and memory management.

  Compile:
		gcc -o Task1 Task1.c
    ...
    gcc -o Task5 Task5.c
  Run:
		./Task1
    ...
    ./Task5

  ---------------Task1-----------------
  -Description: The first task is about memory access. We declare several variables and
  then examine how they are stored in memory.

  -Output:

  --- Integer i ---
Size of i = 4
At Address 0x7fff5eca9b08
The value is 24
At Address 0x7fff5eca9b09
The value is 0
At Address 0x7fff5eca9b0a
The value is 0
At Address 0x7fff5eca9b0b
The value is 0

--- Character c ---
Size of c = 1
At Address 0x7fff5eca9b0f
The value is 97

--- Short s ---
Size of c = 2
At Address 0x7fff5eca9b0c
The value is 57
At Address 0x7fff5eca9b0d
The value is 48

--- Long l ---
Size of l = 8
At Address 0x7fff5eca9b00
The value is 64
At Address 0x7fff5eca9b01
The value is 226
At Address 0x7fff5eca9b02
The value is 1
At Address 0x7fff5eca9b03
The value is 0
At Address 0x7fff5eca9b04
The value is 0
At Address 0x7fff5eca9b05
The value is 0
At Address 0x7fff5eca9b06
The value is 0
At Address 0x7fff5eca9b07
The value is 0

--- Float f ---
Size of f = 4
At Address 0x7fff5eca9afc
The value is 154
At Address 0x7fff5eca9afd
The value is 153
At Address 0x7fff5eca9afe
The value is 25
At Address 0x7fff5eca9aff
The value is 64

--- Double d ---
Size of d = 8
At Address 0x7fff5eca9af0
The value is 154
At Address 0x7fff5eca9af1
The value is 153
At Address 0x7fff5eca9af2
The value is 153
At Address 0x7fff5eca9af3
The value is 153
At Address 0x7fff5eca9af4
The value is 153
At Address 0x7fff5eca9af5
The value is 153
At Address 0x7fff5eca9af6
The value is 233
At Address 0x7fff5eca9af7
The value is 63

  -Answer: The computer I used is a little-Endian machine. We can tell from Long l that data fill lower memory first.


  ---------------Task2-----------------
  -Description: Write a infinite loop to see how much memory we can access.
  -Output:
Address: 0x7fff5723aae8

At Index 0    At Address 0x7fff5723aae8    The Value is 232
At Index 1    At Address 0x7fff5723aae9    The Value is 170
At Index 2    At Address 0x7fff5723aaea    The Value is 35
At Index 3    At Address 0x7fff5723aaeb    The Value is 87
At Index 4    At Address 0x7fff5723aaec    The Value is 255
At Index 5    At Address 0x7fff5723aaed    The Value is 127
At Index 6    At Address 0x7fff5723aaee    The Value is 0
At Index 7    At Address 0x7fff5723aaef    The Value is 0
At Index 8    At Address 0x7fff5723aaf0    The Value is 154
At Index 9    At Address 0x7fff5723aaf1    The Value is 153
At Index 10    At Address 0x7fff5723aaf2    The Value is 153
...
At Index 1297    At Address 0x7fff5723aff9    The Value is 0
At Index 1298    At Address 0x7fff5723affa    The Value is 0
At Index 1299    At Address 0x7fff5723affb    The Value is 0
At Index 1300    At Address 0x7fff5723affc    The Value is 0
At Index 1301    At Address 0x7fff5723affd    The Value is 0
At Index 1302    At Address 0x7fff5723affe    The Value is 0
At Index 1303    At Address 0x7fff5723afff    The Value is 0
Segmentation fault: 11

  -Answer: I can access the memory up to index 1303, and there will have a Segmentation fault at very end.


  ---------------Task3-----------------
  -Description: Write a program that repeatedly allocates a small amount of memory.
  -Answer: When I run the program, Task3 can use up to 100% CPU and 3.4GB memory.


  ---------------Task4-----------------
  -Description: Make a struct that has 3-4 different variables (including some char and short types).
  Set up the structure so it should use an odd number of bytes.
  Write a program that allocates one of these structures.
  Then use the unsigned char * to look at how the memory is laid out.

  -Output:
TracyQ: 2020, ComputerScience

Expected Size: 7 + 2 + 18 = 27
Actual Size: 28

At Address 0x7fff5e407af8   The Value is 84
At Address 0x7fff5e407af9   The Value is 114
At Address 0x7fff5e407afa   The Value is 97
At Address 0x7fff5e407afb   The Value is 99
At Address 0x7fff5e407afc   The Value is 121
At Address 0x7fff5e407afd   The Value is 81
At Address 0x7fff5e407afe   The Value is 0
At Address 0x7fff5e407aff   The Value is 0
At Address 0x7fff5e407b00   The Value is 228
At Address 0x7fff5e407b01   The Value is 7
At Address 0x7fff5e407b02   The Value is 67
At Address 0x7fff5e407b03   The Value is 111
At Address 0x7fff5e407b04   The Value is 109
At Address 0x7fff5e407b05   The Value is 112
At Address 0x7fff5e407b06   The Value is 117
At Address 0x7fff5e407b07   The Value is 116
At Address 0x7fff5e407b08   The Value is 101
At Address 0x7fff5e407b09   The Value is 114
At Address 0x7fff5e407b0a   The Value is 83
At Address 0x7fff5e407b0b   The Value is 99
At Address 0x7fff5e407b0c   The Value is 105
At Address 0x7fff5e407b0d   The Value is 101
At Address 0x7fff5e407b0e   The Value is 110
At Address 0x7fff5e407b0f   The Value is 99
At Address 0x7fff5e407b10   The Value is 101
At Address 0x7fff5e407b11   The Value is 0
At Address 0x7fff5e407b12   The Value is 64
At Address 0x7fff5e407b13   The Value is 94

  -Answer: The size of result doesn't match my expectation. I expect it to be 27 bytes instead of 28 bytes.
           It comes out to be 28bytes because of the padding.


    ---------------Task5-----------------
    -Description: Demonstrate how, by passing a string that is slightly too long to a function,
    you can overwrite a decision variable within the function if the function uses
    strcpy (and don't forget to include string.h) to copy the parameter to a local
    character array of fixed length.

    -Output:
    Abort trap: 6     (On mac)
    safe              (On windows)

Extension:
  I finished five extensions for this project.

    ---------------Extension1-----------------
    -Description: generate a bus error (I wrote two programs that can generate a bus error)
    -Output:
    Bus error: 10

    ---------------Extension2-----------------
    -Description: Find the floating point number in C to which you can add one and get back the same number.
    -Result: 16777216.000000

    ---------------Extension3-----------------
    -Description: Make the safe/hacked C program use a string from the command line.
    (Type in name, age(in English), favoritesports)
    -Output:
Personal Profile:
Name: Tracy
Age: Nineteen
Favorite Sports: Basketball

    ---------------Extension4-----------------
    -Description: What other kinds of run-time errors can you generate with very simple C programs?
    -Answer: Besides Seg fault and bus error, I generated error of overflow and divide by 0

    ---------------Extension5-----------------
    -Description: Do some research regarding a fifth language. Have a paragraph of description for it.
    (I did research about Perl)
