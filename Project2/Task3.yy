/**
* CS333 Fall 2017
* Tracy Quan
* Project 2: Lexical Analysis
* Task3: Make a program that strips an html file of all tags and comments.
* It should also strip the file of all whitespace except for a blank line wherever
* there used to be a <p> tag. Test it on this web page.

* Sep 23, 2017
*/


%%

\<[^<]+\>    printf("");
&gt;        printf(">");
&lt;        printf("<");
[\t\r\f]  printf("");

%%

int main ( int argc, char *argv[] ) {
        if (argc > 1)
          yyin = fopen( argv[1], "r" ); //where yylex reads its input
        yylex();

}
