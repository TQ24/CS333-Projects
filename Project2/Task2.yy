/**
* CS333 Fall 2017
* Tracy Quan
* Project 2: Lexical Analysis
* Task2: Using Flex, make a program that reads in a text file and tells you
* not only the number of rows and characters, but also how many of each vowel
* [a, e, i, o, u] are in the file.

* Sep 23, 2017
*/

          int num_lines = 0, num_chars = 0, num_vowels = 0;  //defines variables

%%

[aeiouAEIOU]        ++num_vowels;       //counts the number of vowels
\n        ++num_lines; ++num_chars;     //counts the number of lines
.         ++num_chars;                  //counts the number of characters

%%

int main ( int argc, char *argv[] ) {
        yyin = fopen("ImHungry.txt","r");
        yylex();
        printf("Number of Lines: %d\n", num_lines);
        printf("Number of Characters: %d\n", num_chars);
        printf("Number of Vowels: %d\n", num_vowels);

}
