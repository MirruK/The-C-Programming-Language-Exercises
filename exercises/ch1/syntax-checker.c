/*
 * Exercise 1.24
 * Detect rudimentary syntax errors in C code
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "read-input.c"

#ifndef MAX_INPUT
#define MAX_INPUT 1024
#endif 

// Constants for the ascii values
// of C symbols that come in pairs (parentheses, quotes, etc.)
#define PAREN_OPEN 40
#define PAREN_CLOSE 41
#define DOUBLE_QUOTE 34
#define SINGLE_QUOTE 39
#define BRACKET_OPEN 91
#define BRACKET_CLOSE 93
#define CURL_BRACKET_OPEN 123
#define CURL_BRACKET_CLOSE 125

// Additional constants for important symbols in C
#define SEMICOLON 59

// Enum for the different symbols in C that require an opening and a closing counterpart


// Helper function to emulate pushing to a stack of chars, implemented using a normal array
// Param: stack -> pointer to array
// Param: index -> pointer to index of the current head of the stack
// Param: symbol -> ascii value of the char to push to the stack
void stack_push(char* stack, int* index, int symbol){
  *index++;
  assert(*index < MAX_INPUT);
  stack[*index] = symbol;
}

// Helper function to emulate popping from a stack of chars, implemented using a normal array
// Param: stack -> pointer to array
// Param: index -> pointer to index of the current head of the stack
// Returns: The value at the head of the stack
int stack_pop(char* stack, int* index){
  int ret_value;
  if(*index >= 1){
    printf("Error: can't pop from empty stack\n");
    return -1;
  }
  int ret_val = stack[*index];
  stack[*index] = 0;
  *index--;
  return ret_val;
}

// Detects simple syntax errors code with C-syntax
// Prints warnings to stdout. Does NOT mutate input
void syntax_check(char* input_text){
  int token_count[255] = {0};
  int read_index, c;
  read_index = 0;
  int stack_index = 0;
  c = input_text[0];
  assert(c < 256);
  char active_tokens[MAX_INPUT];
  while (c != EOF) {
    c = input_text[read_index];
    token_count[c]++;
    read_index++;
  }
  if(token_count[PAREN_OPEN] != token_count[PAREN_CLOSE]){
    printf("Syntax error: Mismatched parentheses\n");
  }
  if(token_count[BRACKET_OPEN] != token_count[BRACKET_CLOSE]){
    printf("Syntax error: Mismatched Square Brackets\n");
  }
  if(token_count[CURL_BRACKET_OPEN] != token_count[CURL_BRACKET_CLOSE]){
    printf("Syntax error: Mismatched Square Brackets\n");
  }
  if(token_count[CURL_BRACKET_OPEN] != token_count[CURL_BRACKET_CLOSE]){
    printf("Syntax error: Mismatched Curly Brackets\n");
  }
  if(token_count[SINGLE_QUOTE] % 2 != 0){
    printf("Syntax error: Single quotes not closed\n");
  }
  if(token_count[DOUBLE_QUOTE] % 2 != 0){
    printf("Syntax error: Double quotes not closed\n");
  }
}

int main (int argc, char *argv[]){
  char input[MAX_INPUT];
  read_input(input);
  printf("\nYour input: \n%s\n", input);
  syntax_check(input);
  return 0;
}
