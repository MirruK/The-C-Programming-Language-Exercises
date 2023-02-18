#include <stdio.h>

// Exercise 1.8
void count_special(){
  int c;
  long nc = 0;
  while ((c = getchar()) != EOF) {
    switch (c) {
      case '\t': ++nc;
        break; 
      case '\n': ++nc;
        break; 
      case ' ': ++nc;
        break; 
      default:
        break;
    }
  }
  printf("Number of tabs, spaces or newlines: %d\n", nc);
}

// Exercise 1.9
void read_modify(){
  int blank, c = 0;
  while ((c = getchar()) != EOF) {
    if(c != ' ' || blank == 0){
      putchar(c);
      if (c == ' '){
        blank = 1;
      }
      else{
        blank = 0;
      }
    }
  }
}

// Exercise 1.10
void read_modify_special(){
  int c;
  while ((c = getchar()) != EOF) {
    switch (c) {
      case '\t': 
        putchar('\\');
        putchar('t');
        break; 
      case '\b':
        putchar('\\');
        putchar('b');
        break; 
      case '\\':
        putchar('\\');
        break; 
      default:
        putchar(c);
        break;
    }
  }
}
int main (int argc, char *argv[])
{
  read_modify_special();
}
