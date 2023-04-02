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
#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */
void print_stack();

#define BUFSIZE 100
int bufp = 0; /* next free position in buf */
char buf[BUFSIZE]; /* buffer for ungetch */

int getch(void);
void ungetch(int);
double pop(void);
void push(double);
int parse_number(char num_buf[]);
int parse_token(char token_buf[]);
double eval_op(char token_buf[]);

double op_add(double op_args[2]){
    return op_args[0] + op_args[1];
};
double op_sub(double op_args[2]){
    return op_args[1] - op_args[0];
};
double op_mul(double op_args[2]){
    return op_args[0] * op_args[1];
};
double op_sin(double op_args[2]){
    return sin(op_args[0]);
};
double op_cos(double op_args[2]){
    return cos(op_args[0]);
};
double op_pow(double op_args[2]){
    return pow(op_args[1], op_args[0]);
};
double op_exp(double op_args[2]){
    return exp(op_args[0]);
};

double (*operator_functions[])() = {op_add, op_sub, op_mul, op_sin, op_cos, op_pow, op_exp};
char* operator_strings[7] = {"+", "-", "*", "sin", "cos", "pow", "exp"};
int operator_nargs[7] = {2, 2, 2, 1, 1, 2, 1};

int main(){
    int action = 0;
    char buffer[100] = {0};
    while(1){ 
        action = parse_number(buffer);
        if (action > -1){
            push(atof(buffer));
        }
        // Do the thing branch
        else if (action == -1) {
            parse_token(buffer);
            push(eval_op(buffer));
            printf("Result of last operation: %f\n", val[sp-1]);
        }
        else {
            printf("Result: %f\n", pop());
            break;
        }
        //printf("Parsed token: %s\n");
        // Print the whole stack
        //print_stack();
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
    
    
}


double eval_op(char token_buf[]){
    for(char k=0; token_buf[k] != '\0'; k++){
        if(token_buf[k] == '\n') {
            token_buf[k] = '\0';
            break;
        }
    }
    // This means there is support for maximum 2 args per operator
    double op_args[2];
    double result = 0;
    // TODO: number of operators is hardcoded, FIX THIS
    for (int j = 0; j < 7; j++){
        if (strcmp(token_buf, operator_strings[j]) == 0){
            for(int i = 0; i < operator_nargs[j]; i++){
                op_args[i] = pop();
            }
            result = (*operator_functions[j])(op_args);
            break;
        }
    }
    return result;
}

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
/* Function to print the stack, for debugging purposes*/
void print_stack(){
    printf("Printing stack\n"); 
    for(int i = 0; i<sp; i++){
        printf("%f\n", val[i]);
    }
}

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
