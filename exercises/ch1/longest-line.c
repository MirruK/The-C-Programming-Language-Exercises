/* Copied and modified version of example from ch1-9
 * For exercise 1-17
 * */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int fetchline(char line[], int lim);
void copy(char to[], char from[]);
/* print the longest input line */
main()
{
  int len; /* current line length */
  int max; /* maximum length seen so far */
  char line[MAXLINE]; /* current input line */
  char longest[MAXLINE]; /* longest line saved here */
  max = 0;
  while ((len = fetchline(line, MAXLINE)) > 0){
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0){ /* there was a line */
    printf("%s", longest);
  }
  return 0;
}
/* fetchline: read a line into s, return length */
int fetchline(char line[],int lim){
  int c, i;
  for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    line[i] = c;
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  printf("Current line length: %4d\n", i);
  printf("Current line: %s\n", line);
  return i;
}
/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
