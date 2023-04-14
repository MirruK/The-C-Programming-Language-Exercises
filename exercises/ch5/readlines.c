#include <stdio.h>
#include <string.h>

int getl(char *ptr){
    char c;
    while((c = getchar()) != EOF){
        *ptr = c; 
        if(c == '\n') return 1;
        ptr++;
    }
    return 0;
}
/* Read from stdin and fill buf with pointers to each line of input */
int readlines(char (*buf)[100]){
    int i = 0;
    int res;
    while(getl(buf[i++]));
    return i-1;
}

/* writelines: write output lines */
void writelines(char (*lineptr)[100], int nlines){
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

int main(){
    // 100 lines of max 100 length each
    int linelen = 100;
    char buf[100][100];
    writelines(buf, readlines(buf));
}
