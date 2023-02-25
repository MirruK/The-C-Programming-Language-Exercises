/*
 * Exercise 1.17-1.19
 * */

#include <stdio.h>
#include <stdlib.h>

#define LINE_LENGTH 80
#define MAX_LENGTH 1024

struct Arr_w_len{
  int array_length;
  char * arr;
};

typedef struct Arr_w_len Arr_w_len;

Arr_w_len fetch_line(){
  int c, curr_len = 0;
  char * line = malloc(sizeof(char)*(MAX_LENGTH+1));
  while ((c = getchar()) != EOF && c != '\n') {
    line[curr_len] = c;
    curr_len++;
  }
  line[curr_len] = '\0';
  Arr_w_len ret_val;
  ret_val.array_length = curr_len;
  ret_val.arr = line;
  return ret_val;
}

// Exercise 1.19
void reverse(char *str, int str_length){
  // Reverses a char array "in place"
  char reversed[str_length-1];
  int j = 0;
  for (int i = str_length-1; i >= 0; --i) {
    reversed[j] = str[i];
    j++;
  }
  for (int i = 0; i < str_length+1; i++) {
    if (i == str_length){
      str[i] = '\0';
    }
    else {
      str[i] = reversed[i];
    }
  }
}

int main (int argc, char *argv[])
{
  Arr_w_len char_arr = fetch_line();
  printf("Length of line: %d\nLine: %s\n", char_arr.array_length, char_arr.arr);
  reverse(char_arr.arr, char_arr.array_length);
  printf("Length of line: %d\nReversed Line: %s\n", char_arr.array_length, char_arr.arr);
  free(char_arr.arr);
  return 0;
}
