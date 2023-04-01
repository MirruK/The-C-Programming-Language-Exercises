#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include <string.h>
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define NOOP 'n'
#define SINE 's'
#define EXP 'e'
#define POW 'p'
int getop(char []);
void push(double);
double pop(void);
/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case SINE:
                push(sin(pop()));
                break;
            case EXP:
                push(exp(pop()));
                break;
            case POW:
                op2 = pop();
                push(pow(pop(),op2));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
                // Exercise 4-3 modulo support
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push((int)pop() % (int)op2);
                else
                    printf("error: zero divisor in modulo operation\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
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
/* print_stack: print the values on the stack */
void print_stack(void)
{
    int sp_cpy = sp;
    while(sp_cpy>=0)
        printf("Value at position %d in stack = %f\n", sp_cpy, val[--sp_cpy]);
}

void print_top(void)
{
    if(sp == 0){
        printf("Stack is empty\n");
    }
    printf("Value at top of stack = %f\n", val[sp-1]);
}

// void duplicate_stack(float dest[])
// {
//     if(sizeof(dest) < sp)
//     {
//         printf("insufficient destination array size\n(Minimum %d elements large)\n", sp);
//     }
//     int sp_cpy = 0;
//     int max_i = sp;
//     while(sp_cpy < max_i)
//     {
//         dest[sp_cpy] = val[sp_cpy];
//         sp_cpy++;
//     }
// }
//
void swap_head(void)
{
    int tmp = val[sp-2];
    val[sp-2] = val[sp-1];
    val[sp-1] = tmp;
}

void clear_stack(void)
{
    while(sp>0){
        val[--sp] = 0;
    }
}

#include <ctype.h>
int getch(void);
void ungetch(int);
int parse_number(char s[]);
void parse_token(char t[]);
/* getop: get next character or numeric operand */
int getop(char s[])
{
    /* Functionality: return NUMBER if number and
     * fill the s buffer with that number as a string
     *
     * Step 1. Get input from user
     * And parse the next relevant token
     * if it is token + \n or just \n,
     * that means user is done inputting
     */

    /* funcs are all valid function keywords
     * funcnum are the return values that
     * tell the calculator to perform that function
     */
    int c;
    char funcs[7][3] = {"%","/","*","+","sin","exp","pow"};
    int funcnum[7] = {'%', '/', '*', '+', SINE, EXP, POW}; 

    // Ignore blankspace and initialize char c
    do {
        c = getch();
    }
    while (c == ' ' || c == '\t');
    if(c== EOF) return EOF;
    if (c == '\n') return '\n';
    if(c != ' ' || c != '\t') ungetch(c);

    if(parse_number(s) != -1) return NUMBER;

    int j, ret;
    j = ret = 0;
    
    char temp[MAXVAL];
    parse_token(temp);

    for (j = 0; j<7; j++){
        if(!strcmp(temp,funcs[j])) return funcnum[j];
    }
    // This is problematic...
    return NOOP;

    // // TODO: fix this so that it treats the getch buffer correctly
    // while(test[j] == temp[j])
    // {
    //     if(test[j+1] == '\0')
    //     {
    //         return 1;
    //     }
    //     j++; 
    // }
    // for(; i!=0; ungetch(temp[i]));
    // return -1;

    // here starts the old version
    // printf("Ran getop\n");
    // char funcs[3][3] = {"sin","exp","pow"};
    // int funcnum[3] = {SINE, EXP, POW}; 
    // int i, j, c;
    // while ((s[0] = c = getch()) == ' ' || c == '\t')
    //     ;
    // s[1] = '\0';
    // if (!isdigit(c) && c != '.'){
    //     // 1. Grab 3 characters into a buffer (better: grab until first non-letter)
    //     // 2. run is_str(buffer, funcs[j])
    //     // 3. on true, return funcnum[j]
    //     // 4. unget 3 chars
    //     ungetch(c);
    //     char temp_buf[4];
    //     for(j = 0;(temp_buf[j] = getch()) && j<3; j++);
    //     temp_buf[3] = '\0';
    //     j = 0;
    //     for(; is_func(temp_buf, funcs[j])==-1 && j<3; j++);
    //     if(j<3) return funcnum[j]; /* not a number */
    //     else return temp_buf[0];
    // }
    // i = 0;
    // if (isdigit(c)) /* collect integer part */
    //     while (isdigit(s[++i] = c = getch()))
    //         ;
    // if (c == '.') /* collect fraction part */
    //         while (isdigit(s[++i] = c = getch()))
    //             ;
    // s[i] = '\0';
    // if (c != EOF)
    //     ungetch(c);
    // return NUMBER;
}

int parse_number(char s[]){
    int c, i;
    int was_digit = 0;
    i = 0;
    c = getch();
    s[i] = c;
    if (isdigit(c)){ /* collect integer part */
        while (isdigit(s[i++] = c = getch()));
        was_digit = 1; 
    }
    if (c == '.') /* collect fraction part */
            while (isdigit(s[i++] = c = getch()))
                ;
    s[i] = '\0';
    if(i < 2 && !was_digit){
        ungetch(s[0]);
        return -1;
    }
    return NUMBER;
}

void parse_token(char test[])
{
    int i, j, c;
    i = c = j = 0;
    char temp[MAXVAL];
    // fill temp with a token
    while(isalpha(c = temp[i] = getch())){
        i++;
    }
    temp[i+1] = '\0';
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
