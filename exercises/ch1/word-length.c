/*
 * Exercises 1.11 - 1.14
 * */

#include <stdio.h>

#define FALSE 0
#define TRUE 1

// Max amount of words whose lengths to include in the historgram
#define MAX_WORDS 1024

// Exercise 1.12
void one_word_per_line(){
  int in_word = FALSE;
  int inp;
  while ((inp = getchar()) != EOF) {
    if(inp == '\t' || inp == ' '){
      if(in_word){
        putchar('\n');
      } else {
        putchar(inp);
      }
      in_word = FALSE;
    }
    else {
      in_word = TRUE;
      putchar(inp);
    }
  } 
}

// Exercise 1.13 (Simplified historgram visualization)
void word_histogram(){
  int inp, wordlength, curr_index = 0;
  int in_word = FALSE;
  int word_lengths[MAX_WORDS];
  while ((inp = getchar()) != EOF) { 
    if(inp == '\t' || inp == ' '){
      in_word = FALSE;
      word_lengths[curr_index] = wordlength;
      wordlength = 0;
      ++curr_index;
    }
    else {
      in_word = TRUE;
      ++wordlength;
    }
  }
  word_lengths[curr_index] = wordlength;
  ++curr_index;
  for (int i = 0; i < curr_index; ++i) {
    printf("Word %4d: %4d\n", i, word_lengths[i]);
  }
}

// Exercise 1.14
void charater_freq_histogram(){
  int inp = 0;
  int chars[26] = {0};
  while ((inp = getchar()) != EOF) { 
      chars[inp-'a']++;
      //printf("curr char: %c, digit: %d\n", inp-'a',inp-'a');
  }
  printf("\nCharacter Frequency Historgram\n");
  for (int i = 0; i < 26; ++i) {
    printf("Char %c: %4d\n", i+'a', chars[i]);
  }
}
int main (int argc, char *argv[])
{
  //one_word_per_line(); 
  //word_histogram();
  charater_freq_histogram();
  return 0;
}
