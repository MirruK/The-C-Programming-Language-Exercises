#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define SINE 's'
#define EXP 'e'
#define POW 'p'
int getop(char []);
void push(double);
double pop(void);
/* reverse Polish calculator */
main()
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
                    push(pop() % op2);
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
        printf("Value at position %d in stack = %f\n", val[--sp_cpy]);
}

void print_top(void)
{
    if(sp == 0){
        printf("Stack is empty\n");
    }
    printf("Value at top of stack = %f\n", val[sp-1]);
}

void duplicate_stack(float[] dest)
{
    if(sizeof(dest) < sp)
    {
        printf("insufficient destination array size\n(Minimum %d elements large)\n", sp);
    }
    int sp_cpy = 0;
    int max_i = sp;
    while(sp_cpy < max_i)
    {
        dest[sp_cpy] = val[sp_cpy];
        sp_cpy++;
    }
}

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
int is_str(char[] comp, int i);
/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
            while (isdigit(s[++i] = c = getch()))
                ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

int is_str(char[] comp, int i)
{
    int c;
    char temp[MAXVAL];
    // TODO: fix this so that it treats the getch buffer correctly
    while((temp[i] = getch()) == comp[i])
    {
        if(comp[i+1] == '\0')
        {
            for(;i>=0; ungetch(temp[i--]));
            return 1;
        }
        i++; 
    }

    return 0;
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
