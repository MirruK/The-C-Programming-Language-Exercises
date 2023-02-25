/*
 * Exercise 1.21
 * Folds long lines into multiple lines of n-columns
 * */

#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 1024
#define MAX_COLUMNS 20

char* fetch_format_input(){
  printf("Ran function\n");
  char* line = malloc(MAX_INPUT);
  int line_len = 0;
  int index = 0;
  int c;
  while ((c=getchar())!= EOF) {
    if(c == '\n'){
      line_len = 0;
    }
    if(line_len > MAX_COLUMNS && c != ' '){
      printf("Hit fold condition\n");
      line[index] = '\n';
      index++;
      line[index] = '-';
      index++;
      line[index] = c;
      line_len = 0;
    }
    else {
      line[index] = c;
    }
    index++;
    line_len++;
  }
  line[index] = '\0';
  return line;
}

int main (int argc, char *argv[])
{
  char* input = fetch_format_input();
  printf("%s\n", input);
  return 0;
}
