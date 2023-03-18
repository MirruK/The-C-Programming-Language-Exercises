// Exercise 2.2
#include <stdio.h>

#define lim 100

int main(){
  int c;
  for(int i = 0; ((i < lim-1) + ((c=getchar()) != '\n' + (c != EOF))) == 0; ++i){
    putchar(c);
  }
}
