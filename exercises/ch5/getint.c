#include <stdio.h>
#include <ctype.h>


int getint(int *ip){
    char c, sign;
    // Skip whitespace
    for(; (c = getchar()) == ' ';);
    // Get optional sign
    if((c=getchar()) == '-' || c == '+'){
        sign = c;
        c = getchar();
        if(isdigit(c)){
            //*ip = sign == '+' ?
        }
    }

    return EOF;
}

int main(){
    //getint();
}
