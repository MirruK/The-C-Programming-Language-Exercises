#define MAX_INPUT 1024
#define TRUE 1
#define FALSE 0

// Fills "buffer" with user input from stdin
// Returns nothing, mutates the memory pointed to by "buffer"
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
