/**
* CS333 Fall 2017
* Tracy Quan
* Project 2: Lexical Analysis
* Extension2: Make the encoder more complex.
* In this extension, I did an encoder and its corresponding decoder.
* The encoder will convert words/sentence to a sequence of double-digit integer.
* The decoder will convert the generated sequence (will look pretty random) back to a readable string.

* Sep 25, 2017
*/

%%
[ \t\r\n]      printf("00");
[a-z]       {
            int input = (int)yytext[0];
            int index = input - 97;
            int output = ((2017/25)+2)*25 + index - 2017;
            printf("%d", output);
}
[1-9][0-9]     {
            int input = atoi(yytext);
            int index = (input + 2017) % 25;
            int ascii = 97+index;
            printf("%c",ascii);
}
00          printf(" ");
%%

int main ( int argc, char *argv[] ) {

        yylex();
        printf("\n");

}
