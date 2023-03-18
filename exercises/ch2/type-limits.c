#include <stdio.h>
#include <limits.h>

int determine_char(){
  char c, n;
  c = 0;
  n = 1;
  // Stop incrementing char when n has overflowed
  // The difference being different than 1 implies an overflow
  while(n - c == 1){
    n++;
    c++;
  }
  return c;
}

int main (int argc, char *argv[]){
  printf("Char upper bound: %d\n", CHAR_MAX);
  printf("Char number of unique values: %d\n", CHAR_MAX-CHAR_MIN);
  printf("Max bound of char determined by computation: %d\n", determine_char());
  // Now repeat for all the *_MAX constants
  // and U*_MAX for the bounds of unsigned types
  return 0;
}
