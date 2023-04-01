#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

// Feels redundant rn, might use if necessary
// enum OPERATORS{
//      PLUS,
//      MINUS,
//      SINE,
//      COSINE,
//      POW,
//      EXP 
// };

// Declarations (Move to header file later)
int getch(void);
void ungetch(int);
double pop(void);
void push(double);
int parse_number(char num_buf[]);
int parse_token(char token_buf[]);

double add(double a, double b){
    return a + b;
};
double sub(double a, double b){
    return a - b;
};
double (*operator_functions[])() = {add, sub, sin, cos, pow, exp};
char operator_strings[6][3] = {"add", "sub", "sin", "cos", "pow", "exp"};

int main(){
    int action = 0;
    char buffer[100] = {0};
    while(1){ 
        action = parse_number(buffer);
        if (action > -1){
        }
        else if (action == -1) parse_token(buffer);
        else break;
        printf("Parsed token: %s\n", buffer);
    }
}

// int parse_number(char num_buf[])
// returns -1 for not a number, 1 if valid number was parsed
// number_buf is the buffer to which the number as a string will be written
int parse_number(char num_buf[]){
    char c = 0;
    int i = 0;
    c = getch();
    // Skip all whitespace characters
    // If any of them are newline of EOF, return early
    while(c == ' '){
        if(i == 1) num_buf[--i] = 0;
        if (c == '\n') {
            //ungetch(c);
            return -1;
        }
        if (c == EOF){
            return -2;
        }
        c = getch();
    }
    if (c == EOF){
        return -2;
    }
    num_buf[i] = c;
    // Consume integer part
    if (isdigit(c)) /* collect integer part */
        while (isdigit(num_buf[++i] = c = getch()))
            ;
    /* collect fraction part */
    if (c == '.'){ 
        // Allow inputs in the format .xxx, that means 0.xxx
        if (i == 0) num_buf[i] = '0', num_buf[++i] = '.';
        while (isdigit(num_buf[++i] = c = getch()));
    }
    if(isalnum(c)) {
        for(; i>-1; i--){
            printf("ungot char %c\n", num_buf[i]);
            ungetch(num_buf[i]);
        }
        return -1;
    }
    if (i == 0){ 
        ungetch(c);
        return -1;
    }
    // num_buf[i] = '\0';
    // if (c != EOF)
    //     ungetch(c);
    num_buf[i+1] = '\0';
    return 1;
}

// int parse_token(char token_buf[])
// returns -1 for invalid token, otherwise returns an integer corresponding
// to the same token in the OPERATORS enum
int parse_token(char token_buf[]){
    char c = 0;
    int i = 0;
    c = getch();

    // Skip all whitespace characters
    // If any of them are newline of EOF, return early
    while(c == ' '){
        if(i == 1) token_buf[--i] = '0';
        if (c == '\n' || c == EOF) {
            //ungetch(c);
            return -1;
        }
        c = getch();
    }
    token_buf[i] = c;
    while(isalnum(token_buf[++i] = c = getch()));
    token_buf[i+1] = '\0';
    return 1;
    
    // for (int j=0; j<sizeof(operator_strings); j++){
    //     if (strcmp(token_buf, operator_strings[j]) == 0){
    //          
    //     }
    // }
    
}

#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */
/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}
/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
