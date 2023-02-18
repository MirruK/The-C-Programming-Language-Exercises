/*
 * Exercises 1.11 - 1.14
 * */

#include <stdio.h>

#define FALSE 0
#define TRUE 1

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

int main (int argc, char *argv[])
{
  one_word_per_line(); 
  return 0;
}
