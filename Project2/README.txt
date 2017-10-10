CS333 - Project # - README
Your Name

Directory Layout:
proj03/
|
|__/C/
|  |
|  |__/Task1.yy
|  |__/Task1.yy.c
|  |__/Task1
|  |__/Task2.yy
|  |__/Task2.yy.c
|  |__/Task2
|  |__/Task3.yy
|  |__/Task3.yy.c
|  |__/Task3
|  |__/Task4.yy
|  |__/Task4.yy.c
|  |__/Task4
|  |__/Extension2.yy
|  |__/Extension2.yy.c
|  |__/Extension2
|  |__/Extension3.yy
|  |__/Extension3.yy.c
|  |__/Extension3
|
|__/JavaScript/
|  |
|  |__/task*.rs
|
|__/Bash/
|  |
|  |__/task*.scala
|
|__/C++/
|  |
|  |__/task*.rs

---------------------------Summary----------------------------------
The first thing we have to do with any programming language is build a lexical
analyzer that converts a text string into a series of tokens. There are lots of
tools for handling this. For this assignment, you'll make use of the Flex lexical
analysis tool and build a few different parsers.

---------------------------Task 1----------------------------------
Description:
Using flex, make a program called encode that takes any character in a-z
or A-Z and shifts it 13 spaces forward in the alphabet, with wraparound
from z back to a.

Command Line:
flex -o Task1.yy.c Task1.yy
gcc -o Task1 Task1.yy.c -ll
echo abcdefghijklmnopqrstuvwxyz |./Task1

Output:
n ---- from a
o ---- from b
p ---- from c
q ---- from d
r ---- from e
s ---- from f
t ---- from g
u ---- from h
v ---- from i
w ---- from j
x ---- from k
y ---- from l
z ---- from m
b ---- from n
c ---- from o
d ---- from p
e ---- from q
f ---- from r
g ---- from s
h ---- from t
i ---- from u
j ---- from v
k ---- from w
l ---- from x
m ---- from y
n ---- from z


---------------------------Task 2----------------------------------
Description:
Using Flex, make a program that reads in a text file and tells you
not only the number of rows and characters, but also how many of each vowel
[a, e, i, o, u] are in the file.

Command Line:
flex -o Task2.yy.c Task2.yy
gcc -o Task2 Task2.yy.c -ll
./Task2 ImHungry.txt

Output:
Number of Lines: 7
Number of Characters: 181
Number of Vowels: 80


---------------------------Task 3----------------------------------
Description:
Make a program that strips an html file of all tags and comments.
It should also strip the file of all whitespace except for a blank line wherever
there used to be a <p> tag. Test it on this web page.

Command Line:
flex -o Task3.yy.c Task3.yy
gcc -o Task3 Task3.yy.c -ll
./Task3 test.txt

Output:
Project 2 | CS 333




  CS 333



            Topics
Notes

Homework

Homework 1
Homework 2
Homework 3
Homework 4
Homework 5
Homework 6
Homework 7
Homework 8
Homework 9



Projects

Project 1
Project 2
Project 3
Project 4
Project 5
Project 6
Project 7
Project 8
Project 9


Reference Materials








CS 333 Programming Languages
Project 2



$(function(){$("#index").addClass("active")})

    Lexical Analysis

    The first thing we have to do with any programming language is build a lexical analyzer
that converts a text string into a series of tokens. There are lots of tools for handling
this. For this assignment, you'll make use of the Flex lexical analysis tool and
build a few different parsers.

    Tasks
Flex is an open source lexical analysis tool. The way it works is you first create an input
file that defines symbols and production rules that describe how to parse a text file. Then
you run Flex and it produces a C file. You can then compile the C file and run it on some input.

    As an example, consider the following Hello World program for Flex. The line
beginning with blah defines a rule that says to replace instances of blah
with hello world.


/**
 * Hello World: replace "blah" with "hello world"
 */

 %%

 blah    printf("hello world");

 %%

 int main ( int argc, char *argv[] ) {

 yylex();

 }


    If you type the above into a file called replace.yy and then execute the following
commands, you get the resulting behavior.

     $ flex replace.yy
     $ gcc -o repl lex.yy.c -lfl
 $ echo "blah and another blah" | ./repl
 hello world and another hello world

The documentation for flex provides many
more examples and a description of the syntax.

Note that flex is based on regular expressions, which are similar to the extended BNF notation
we've gone over in class. There are lots of
documentation for regular expressions, and they can be very useful in many situations.


 Using flex, make a program called encode.yy that takes any character in a-z or A-Z
and shifts it 13 spaces forward in the alphabet, with wraparound from z back to a. Run it on a
text file of your choice. You can test that it is working correctly by running the output of
encode.yy through encode again. The result should be the original document.


Using Flex, make a program that reads in a text file and tells you not only the number
of rows and characters, but also how many of each vowel [a, e, i, o, u] are in
the file.


Make a program that strips an html file of all tags and comments. It should also strip
the file of all whitespace except for a blank line wherever there used to be a
<p> tag. Test it on this web page. Here is a
downloadable version.

Note that this is challenging to do in a way that make the output reasonably formatted.
As an extension, you can make your program do more sophisticated things like replace
&amp;gt; with >.


Implement a parser for Clite. For now, the output of your program should just be a
sequence of strings, one per line. Please use the following strings.




Integer-<value>
A sequence of one or more digits.


Float-<value>
An integer, a dot, and another integer.


Keyword-<word>
if | else | while | for | int | float


Identifier-<name>
Legal names/identifiers.


Assignment
 =


Comparison-<symbol>
== | < | > | <= | >=


Operator-<symbol>
+ | - | * | /


Open-bracket
 {


Close-bracket
 }


Open-paren
 (


Close-paren
 )




Ideally, your program should also ignore comments. You can test your program on this
example. You should get something
like this result.


Extensions

 Get comments working properly. Be sure to try out a variety of examples.
 Make the encoder more complex.
 Make the program for analyzing a document to some more interesting things.



&copy; 2016 Ying Li. Page last modified:
document.write(Date(document.lastModified));
.


---------------------------Task 4----------------------------------
Description:
Implement a parser for Clite. For now, the output of your program should
just be a sequence of strings, one per line.

Command Lines:
flex -o Task4.yy.c Task4.yy
gcc -o Task4 Task4.yy.c -ll
./Task4 Task4test.c

Output:
Keyword<int>
 Identifiers<main>
Open-paren
Close-paren
 Open-bracket




  Keyword<int>
 Identifiers<a>
 Assignment
 Integer<6>

  Keyword<int>
 Identifiers<b>
 Assignment
 Float<5.0>


  Keyword<if>
Open-paren
 Identifiers<a>
 Comparison<<>
 Identifiers<b>
 Close-paren
 Open-bracket

    Identifiers<a>
 Assignment
 Identifiers<a>
 Operator<+>
 Identifiers<b>

  Close-bracket


Close-bracket


---------------------------Extension 1----------------------------------
Description:
Get comments working properly in your parser for Clite. Be sure to try out a variety of examples.
The ignored comments include "//" and multiple lines "/*...*/"

Command Lines: (changed my code in task4 file)
flex -o Task4.yy.c Task4.yy
gcc -o Task4 Task4.yy.c -ll
./Task4 Task4test.c

Output:
Keyword<int>
 Identifiers<main>
Open-paren
Close-paren
 Open-bracket




  Keyword<int>
 Identifiers<a>
 Assignment
 Integer<6>

  Keyword<int>
 Identifiers<b>
 Assignment
 Float<5.0>


  Keyword<if>
Open-paren
 Identifiers<a>
 Comparison<<>
 Identifiers<b>
 Close-paren
 Open-bracket

    Identifiers<a>
 Assignment
 Identifiers<a>
 Operator<+>
 Identifiers<b>

  Close-bracket


Close-bracket

---------------------------Extension 2----------------------------------
Description:
Extension2: Make the encoder more complex.
In this extension, I did an encoder and its corresponding decoder.
The encoder will convert words/sentence to a sequence of double-digit integer.
The decoder will convert the generated sequence (will look pretty random) back to a readable string.

Command Lines:
flex -o Extension2.yy.c Extension2.yy
gcc -o Extension2 Extension2.yy.c -ll
echo i am tracy|./Extension2

Output:
4100334500525033355700

Command Line:
echo 4100334500525033355700|./Extension2

Output:
i am tracy 00

---------------------------Extension 3----------------------------------
Description:
Extension3: Make the parser for analyzing a document to some more interesting things.
Only print words that have less than six characters.

Command Lines:
flex -o Extension3.yy.c Extension3.yy
gcc -o Extension3 Extension3.yy.c -ll
./Extension3 ImHungry.txt

Output:
I want to  this    night.
I wanna eat  Roast Duck.
I wanna eat Dim Sum.
I wanna eat .
I wanna eat green tea ice cream.
I need to stop  this file  it makes me .

---------------------------Extension 4----------------------------------
Description:
Make my Task3 program do more sophisticated things like replace &gt; with >.

Command Lines&Output: Same with Task3

---------------------------Extension 5----------------------------------
Description:
I added the third language C++, see my CS333 Homepage.
