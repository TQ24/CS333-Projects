/* Project 6
 * Part 1: File I/O and String in C
 * Tracy Quan
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define Max_words    10000      //the capacity of the words list
#define Max_string   100        //the max length of a word

/* define a word dictionary struct that holds the word and its frequency. */
typedef struct worddict {
  char s[Max_string];    //the word
  int freq;              //the number of occurences
} word;

/* insert a word into the words list */
/* parameters: word *words - the words list;
 *             int *n - the length of the list;
 *             char *s - the current string;
 */
void insert_word(word *words, int *n, char *s){
  int i;
  /* Error check */
  if (*n>Max_words){
    printf("Too many words!\n");
    exit(1);
  }
  else if (strlen(s)>=Max_string){
    printf("This word is too long!\n");
    exit(1);
  }

  /* if the current word is already in the list. */
  for (i=0; i<*n; i++){
    if (strcmp (s,words[i].s) == 0){
      words[i].freq++;
      return;
    }
  }
  /* if the current word is new. */
  strcpy(words[*n].s, s);           // copy the string to the list
  words[*n].freq = 1;               // set the new word's frequency to 1
  (*n)++;                           // increase the list's size by 1
}

/* compare two words according to their frequencies. */
int wordcmp( word *a, word *b){
  if (a->freq > b->freq){
    return -1;
  }
  else if (a->freq < b->freq){
    return 1;
  }
  else {
    return 0;
  }
}

/* transfer all characters to lowercase. */
void char_lowercase(char *s){
  int i;
  for (i=0; s[i]; i++){
    s[i]= tolower(s[i]);
  }
}

/* return 1 if the char is from a-z or a-z
 * otherwise, return 0.
 */
int valid_char(char c){
  if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'){
    return 1;
  }
  else {
    return 0;
  }
}

/* delete the i th char in the string. */
void delete_char(char *s, int i){
  while (s[i]){
    i++;
    s[i-1]=s[i];        // move every char after the i th forward.
  }
  s[i]=8;             // assign the last char to an invalid char
}

/* delete all invalid characters. */
void delete_invalid(char *s){
  int i;
  for (i=0; s[i]; i++){
    if (valid_char(s[i])==0){
      delete_char(s, i);
    }
  }
}

/* the main program. */
int main(int argc, char *argv[]){
  if (argc<2){
    printf("Please enter a valid filename");
  }
  FILE *fp;
  word words[Max_words];
  char s[5000];
  int size = 0;
  fp = fopen(argv[1],"r");
  if (fp==NULL){
    printf("This file doesn't exist");
  }
  while (fscanf(fp, "%s", s)!=EOF){

    if (valid_char(s[0])==1){         // if the first char of s is valid
      delete_invalid(s);              // delete all invalid chars in the word
      char_lowercase(s);              // switch all characters to lowercase
      insert_word(words, &size, s);   // insert word to the list.
    }
  }
  qsort((void *)words, size, sizeof(word), (int (*)(const void *, const void *)) wordcmp);

  int display;

  if (size<20){
    display = size;
  }
  else{
    display = 20;
  }

  for (int i=0; i<display; i++){
    printf("%s\n%d\n", words[i].s, words[i].freq );
  }
  fclose(fp);
  return 0;
}
