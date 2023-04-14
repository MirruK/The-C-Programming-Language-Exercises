#include <stdio.h>
#include <string.h>

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

void mystrncat(char *t, char *s, int n){
    for(int i = 0; *t != '\0'; t++, s++, i++){
        *s = *t;
        if(i >= n) return;
    }
    *s = '\0';
}

int mystrncmp(char *s1, char *s2, int n){
    int i;
    for(i = 0; ; i++){
        if(i >= n){ 
            if(s1[i] == '\0' && s2[i] == '\0') return 0;
            if(s1[i] == '\0') return -1;
            if(s2[i] == '\0') return 1;
            if(s1[i] == s2[i]); 
            else if(s1[i] > s2[i]){
                return 1; 
            }
            else return -1;
        }
    }
}

/* my strend - returns 1 if string t occurs at the 
 * end of string s, 0 otherwise 
 * */
int mystrend(char *s, char *t){
    int firstlen = mystrlen(s);
    int otherlen = mystrlen(t);
    // Skip len(s) - len(t) chars in s to align the strings
    for(int i = 0; i<firstlen-otherlen; i++, s++);
    for(; *s != '\0'; s++, t++){
        if(*s != *t){
            return 0;
        }
    }
    return 1;
}

int main(){
    char start[100] = "This is at the start";
    // char *end = ", I am concatenated :)";
    char *end = "rt";
    printf("Result of mystrend: %d\n", mystrend(start, end));
    // mystrcat(end, start);
    //printf("%s\n", start);
}
