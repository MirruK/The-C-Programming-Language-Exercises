#include <stdio.h>

// Return index of last occurence of string t in string s
// Returns index or -1 if no match is found
int strindex(char s[], char t[]){
    int sind, tind, temp, found;
    found = -1;
    sind = tind = temp = 0;
    while(s[sind] != EOF && s[sind] != '\0'){
        if (s[sind] == t[tind]){
            if(tind == 0) temp = sind;
            sind++;
            tind++;
        }
        else{
            sind += temp + 1;
            tind = temp = 0;
        }
        // Early return here to make function 
        // return index of first occurence
        if(t[tind] == '\0') found = temp;
    }
    return found;
}

int main(){
    char str[] = "Check this for matches";
    char substr[] = "D";
    printf("Checking if string \"%s\" is in \"%s\"\n", substr, str);
    printf("The index of the match is at: %d\n", strindex(str, substr));
    return 0;
}


