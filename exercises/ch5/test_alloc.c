#include "./alloc.c"
#include <stdio.h>
#include <string.h>

int main(){
    // Allocate a buffer of 100 chars
    char *p_buf = alloc(100); 
    char *orig = p_buf;
    char some_str[] = "This is getting copied into a buffer allocated with a custom function";
    int i;
    for(i = 0; some_str[i] != '\0'; i++){
        //printf("Adding char: %c to buffer\n", some_str[i]);
        p_buf[i] = some_str[i];
    }
    printf("putting null byte at %d\n", i);
    p_buf[i] = '\0';
    //strcpy(some_str, p_buf);
    //while(*orig != '\0')
    printf("%s\n", orig);
}
