/**
* CS333 Fall 2017
* Tracy Quan
* Project 2: Lexical Analysis
* Task1: Using flex, make a program called encode that takes any character in a-z
*        or A-Z and shifts it 13 spaces forward in the alphabet, with wraparound
*        from z back to a.
* Sep 22, 2017
*/

%%

[a-z]    {
          int index = (int)yytext[0]-97+13;     //finds the index of the new character
          int newascii;
          if (index>25){
            newascii = 97+(index-25);           //finds the ascii value of the new character
          }
          else{
            newascii = 97 + index;              //finds the ascii value of the new character
          }
          printf("%c ---- from %c\n",newascii, yytext[0]);
}
[A-Z]    {
          int index = (int)yytext[0]-65+13;
          int newascii;
          if (index>26){
            newascii = 65 + index - 25;
          }
          else{
            newascii = 65 + index;
          }
          printf("%c ---- from %c\n",newascii, yytext[0]);
}

%%

int main ( int argc, char *argv[] ) {

        yylex();

}
