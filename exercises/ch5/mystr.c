#include <stdio.h>

/* my strlen - get the length of a string */
int mystrlen(char *s){
    char *orig = s;
    while(*s != '\0') s++; 
    return s-orig;
}

/* my strcat - Copies string t to the end of string s */
void mystrcat(char *t, char *s){
    for(; *t != '\0'; t++, s++){
        *s = *t;
    }
    *s = '\0';
}

/* my strend - returns 1 if string t occurs at the 
 * end of string s, 0 otherwise 
 * */
int mystrend(char *s, char *t){
    int firstlen = mystrlen(s);
    int otherlen = mystrlen(t);
    // Skip len(s) - len(t) chars in s to align the strings
    for(int i = 0; i<firstlen-otherlen; 
    for(; *s != '\0'; s++, t++){
         
    }
}

int main(){
    char start[100] = "This is at the start";
    char *end = ", I am concatenated :)";
    mystrcat(end, start);
    printf("%s\n", start);
}
