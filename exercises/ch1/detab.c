/*
 * Exercise 1.20
 * Replace tabs with corresponding amount of spaces
 * */

#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 1024
#define TABSIZE 4

int len_and_tabs(char* str){
  int c = str[0];
  int ind = 0;
  int tabs = 0;
  while (c != '\0') {
    c = str[ind];
    if (c == '\t') {
      tabs++;
    }
    ind++;
  }
  printf("Len: %d, Tabs: %d\n", ind, tabs);
  return ind+tabs*4;
}

void get_input(char * input){
  int c,index = 0;
  while((c = getchar()) != EOF){
    input[index] = c;
    index++;
  }
  printf("\n");
  input[index] = '\0';
}

char* replace_tabs(char * str){
  char *temp = malloc(sizeof(char)*len_and_tabs(str));
  int curr_char = str[0];
  int index = 0;
  int temp_index = 0;
  while (curr_char != '\0') {
    curr_char = str[index];
    if(curr_char == '\t'){
      for (int i = 0; i < TABSIZE; i++) {
        temp[temp_index] = ' ';
        temp_index++;
      }
      index++;
    }
    else {
      temp[temp_index] = curr_char;
      index++;
      temp_index++;
    }
  }
  temp[temp_index] = '\0';
  return temp;
}

int main (int argc, char *argv[])
{
  char inp[MAX_INPUT];
  get_input(inp);
  char* replaced;
  replaced = replace_tabs(inp);
  printf("Your input:\n\"\n%s\n\"\n", inp);
  printf("Your input modified:\n\"\n%s\n\"\n", replaced);
  return 0;
}
