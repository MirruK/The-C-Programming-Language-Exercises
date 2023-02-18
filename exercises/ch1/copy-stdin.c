/*
 * Exercises 1.6-1.7
 * */

#include <stdio.h>

int main (int argc, char *argv[])
{
  int inp = getchar();
  printf("Value of the expr. inp != EOF: %d\n", inp != EOF);
  printf("EOF value: %d\n", EOF);
  while (inp != EOF) {
    putchar(inp);
    inp = getchar();
  }
  return 0;
}
