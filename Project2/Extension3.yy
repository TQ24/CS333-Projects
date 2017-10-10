/**
* CS333 Fall 2017
* Tracy Quan
* Project 2: Lexical Analysis
* Extension3: Make the parser for analyzing a document to some more interesting things.
* Only print words that have less than six characters.
* Sep 25, 2017
*/

%%
[a-zA-Z]{6,}     printf("");

%%

int main ( int argc, char *argv[] ) {
        if (argc > 1)
          yyin = fopen( argv[1], "r" ); //where yylex reads its input
        yylex();
        printf("\n");

}
