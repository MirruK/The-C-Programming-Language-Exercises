/*
 * Exercises 2-4 and 2-5 
 */

#include <stdio.h>

#define TRUE 1
#define FALSE 0

// while str[i] in str2
// --> off++
// --> delete str[i+off]
int char_in(char c, char str[]){
    int i = 0;
    char curr = str[i];
    while(curr != '\0'){
        if (curr == c){
            return TRUE;
        }
        curr = str[++i]; //i incremented before array indexing
    }
    return FALSE;
}


int string_length(const char *str){
    int i = 0;
    char c = str[i];
    while(c != '\0'){
        i++;
        c = str[i];
    }
    return i;
}

void squeeze(char s1[], char s2[]){
    int offset = 0;
    int size = string_length(s1);
    for(int i = 0; i < size; ++i){
        while(char_in(s1[i+offset], s2)){
            ++offset;
        }
        s1[i] = s1[i+offset];
    }
}

int any(char s1[], char s2[]){
    int size = string_length(s1);
    for(int i = 0; i < size; ++i){
        if(char_in(s1[i], s2)){
            return i;
        }
    }
    return -1;
}

int main(){
    char str1[] = "The name is Mirek, I remove m's";
    char str2[] = "ö";
    printf("String before deletion %s\n", str1);
    printf("Location of any character from %s in %s: %d\n", str2, str1, any(str1,str2));
    squeeze(str1, str2);
    printf("String after deletion %s\n", str1);
    return 0;
}
