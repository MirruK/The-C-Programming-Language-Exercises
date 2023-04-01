#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

enum OPERATORS{
     PLUS,
     MINUS,
     SINE,
     COSINE,
     POW,
     EXP 
};

double add(double a, double b){
    return a + b;
};
double sub(double a, double b){
    return a - b;
};
double (*operator_functions[])() = {add, sub, sin, cos, pow, exp};

// int parse_number(char number_buf[])
// returns -1 for not a number, 1 if valid number was parsed
// number_buf is the buffer to which the number as a string will be written

// int parse_token(char token_buf[])
// returns -1 for invalid token, otherwise returns an integer corresponding
// to the same token in the OPERATORS enum
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
