/*
 * Exercise 1.23
 * Removes all C-syntax comments from text input
 * */

#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 1024
#define TRUE 1
#define FALSE 0

void read_input(char* buffer){
  int c, index;
  index = 0;
  while ((c = getchar()) != EOF) {
    if(index == MAX_INPUT-1){
      printf("\nMaximum input size exceeded\n");
      break;
    }
    buffer[index] = c;
    index++;
  }
  buffer[index] = '\0';
}

// Remove double forward slash comments from input string
// by mutating the passed argument "input_buffer"
void remove_comments(char* input_buffer){
  int curr_char, next_char, read_index, write_index, in_comment;
  char modified_input[MAX_INPUT];
  in_comment = read_index = write_index = 0;
  next_char = input_buffer[0];
  while (next_char != '\0') {
    curr_char = input_buffer[read_index];
    next_char = input_buffer[read_index+1];
    if(curr_char == '/' && next_char == '/'){
      in_comment = TRUE;
    }
    if (curr_char == '\n') {
      in_comment = FALSE;
    }
    if (!in_comment) {
      modified_input[write_index] = curr_char;
      write_index++;
    }
    read_index++;
  }
  modified_input[write_index] = '\0';
  read_index = 0;
  curr_char = modified_input[read_index];
  while (curr_char != '\0') {
    input_buffer[read_index] = curr_char;
    read_index++;
    curr_char = modified_input[read_index];
  }
  input_buffer[read_index] = '\0';
}

int main (int argc, char *argv[])
{
  char input_buffer[MAX_INPUT];
  read_input(input_buffer);
  printf("\nwith comments: \n%s\n", input_buffer);
  remove_comments(input_buffer);
  printf("\nw/o comments: \n%s\n", input_buffer);
  return 0;
}
