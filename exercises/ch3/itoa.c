#include <stdio.h>
#include <string.h>
#include <limits.h>

/* reverse: reverse string s in place (function copied from book) */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int negate(int n){
    if (n == INT_MIN){
        return INT_MAX;
    }
    return -n;
}

int nchars_in_int(int n){
    int i = 0;
    do{
        i++;
    }while((n /= 10) > 0);
    return i;
}

/* itoa: convert n to characters in s 
 * (fixed version of function copied from book)
 * exercise 3-4 and 3-6 (for the added min_width parameter)
 */
void itoa(int n, char s[], int min_width)
{
    //int nchars = nchars_in_int(n);
    int i, sign;
    i = 0;
    if ((sign = n) < 0) /* record sign */
        n = negate(n); /* make n positive */
    do { /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0); /* delete it */
    for (; i<min_width; ++i){
        s[i] = '0'; 
    }
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

// Exercise 3-5
char get_digit(int n, int b){
    return n < 10 ? n + '0' : 'A' + n - 10;
}

// This works... somehow
// Exercise 3-5
void itob(int n, char s[], int b){
    int i, sign;
    if ((sign = n) < 0) /* record sign */
        n = negate(n); /* make n positive */
    i = 0;
    do { /* generate digits in reverse order */
        s[i++] = get_digit(n % b, b); /* get next digit */
    } while ((n /= b) > 0); /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s); 
}


int main(){
    char buffer[100];
    itoa(255, buffer, 5);
    printf("Our stringified digit: %s\n", buffer);
    return 0;
}
