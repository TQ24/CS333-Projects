/**
* CS333 Fall 2017
* Tracy Quan
* Project 2: Lexical Analysis
* Task4: Implement a parser for Clite. For now, the output of your program should
* just be a sequence of strings, one per line.

* Sep 24, 2017
*/

%%
\/\/.*$                       printf("");  // ignore the comments starting with "//"; Extension1
\/\*.*?\*\/                   printf("");  // ignore C-style multi-line comments; Extension1
[-+]?[0-9]+                   printf("Integer<%s>\n",yytext);
[-+]?[0-9]*\.[0-9]*           printf("Float<%s>\n",yytext);
if|else|while|for|int|float   printf("Keyword<%s>\n", yytext);
[a-zA-Z][a-zA-Z0-9]*          printf("Identifiers<%s>\n",yytext);
=                             printf("Assignment\n");
==|<|>|<=|>=                  printf("Comparison<%s>\n",yytext);
\+|\-|\*|\/                   printf("Operator<%s>\n",yytext);
\{                            printf("Open-bracket\n");
\}                            printf("Close-bracket\n");
\(                            printf("Open-paren\n");
\)                            printf("Close-paren\n");
;                             printf("");

%%

int main ( int argc, char *argv[] ) {
        if (argc > 1)
          yyin = fopen( argv[1], "r" ); //where yylex reads its input
        yylex();

}
