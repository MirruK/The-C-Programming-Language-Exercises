#include <stdio.h>
#include <ctype.h>

#define MAX_BUF 100
int buf_ind = 0;
char buf[MAX_BUF];

int getch(){
    return buf_ind > 0 ? buf[--buf_ind] : getchar();
}
void ungetch(char c){
    if(buf_ind == MAX_BUF){
        printf("char buffer max size exceeded");
        return;
    }
    buf[buf_ind++] = c;
}


int getint(int *ip){
    char c, sign;
    sign = 1;
    // Skip whitespace
    while(isspace(c = getch()));
    // Get optional sign
    if(c == '-' || c == '+'){
        sign = c;
        // Get next character only if sign was found
        c = getch();
        if(isdigit(c)){
            sign = sign == '-' ? -1 : 1;
        }
        // Early return if sign not succeeded by digit
        else {
            ungetch(c);
            ungetch(sign);
            return 0;
        }
    }
    // Did not find a number
    if (!isdigit(c) && c != EOF){
        ungetch(c);
        return 0;
    }


    for(*ip = 0; isdigit(c); c = getch()){
        *ip = 10 * (*ip) + (c - '0');
    }
    *ip *= sign;
    if(c != EOF){
        ungetch(c);
        return 1;
    }
    return c;
}

int getfloat(float *fp){
    char c, sign;
    sign = 1;
    // Skip whitespace
    while(isspace(c = getch()));
    // Get optional sign
    if(c == '-' || c == '+'){
        sign = c;
        // Get next character only if sign was found
        c = getch();
        if(isdigit(c)){
            sign = sign == '-' ? -1 : 1;
        }
        // Early return if sign not succeeded by digit
        else {
            ungetch(c);
            ungetch(sign);
            return 0;
        }
    }
    // Did not find a number
    if (!isdigit(c) && c != EOF){
        ungetch(c);
        return 0;
    }

    // Get integer part
    for(*fp = 0; isdigit(c); c = getch()){
        *fp = 10 * (*fp) + (c - '0');
    }

    if(c == '.'){
        float scale = 1; 
        float float_part = 0;
        // Get integer part
        for(c = getch(); isdigit(c); c = getch()){
            scale *= 10;
            float_part = 10 * float_part + (c - '0');
        }
        *fp += (float_part / scale);
    }

    *fp *= sign;
    if(c != EOF){
        ungetch(c);
        return 1;
    }
    return c;
}

int main(){
    int test = 0;
    int *p_test = &test;
    printf("Please input an integer:\n");
    if(getint(p_test) != 0){
        printf("Found integer: %d in stdin\n", test);
    }
    else{
        printf("Did not find an integer");
    }
    float test_f = 0;
    float *p_f = &test_f;
    printf("Please input a float:\n");
    if(getfloat(p_f) != 0){
        printf("Found float: %f in stdin\n", test_f);
    }
    else{
        printf("Did not find an integer");
    }

}
