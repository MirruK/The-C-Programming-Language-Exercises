#include <ctype.h>
#include <stdio.h>

// Function atof copied from book
// Modified for exercise 4-2
double atof(char s[]){
    double val, power;
    int i, sign, powersign, powerval;
    long int powtemp;

    // Skip whitespace in input
    for (i = 0; isspace(s[i]); i++);

    // Get optional sign from string
    sign = s[i] == '-' ? -1 : 1;
    if (s[i] == '-' || s[i] == '+') i++;

    // Start producing non-fractional part
    for (val = 0.0; isdigit(s[i]); i++){
        // val = next power of 10 * val + single digit offset
        val = 10.0 * val + (s[i] - '0');
    }
    // If first non-digit is a dot we know decimal part comes next
    // If not, the following for loop wont execute (due to isdigit)
    if (s[i] == '.') i++;
    for (power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    // Now look for optional scientific notation e or E
    // followed by optional sign and a value
    if (s[i] == 'e' || s[i] == 'E') i++;
    else return sign * val / power;
    powersign = s[i] == '-' ? -1 : 1;
    if (s[i] == '-' || s[i] == '+') i++;
    for (powerval = 0; isdigit(s[i]); i++){
        // val = next power of 10 * val + single digit offset
        powerval = 10.0 * powerval + (s[i] - '0');
    }
    val = sign * val / power;
    powtemp = 1;
    for (; powerval>0; powerval--) powtemp *=10;
    printf("Value of powtemp %d\n", powtemp);
    if (powersign == -1) return val / powtemp;
    else return val * powtemp;
}

int main(){
    char myascii_f[] = "112.358";
    printf("From string (\"%s\") to double: %f\n", myascii_f,  atof(myascii_f)); 
    char my_sci[] = "1.23E10";
    printf("From string (\"%s\") with scientific notation to double: %f\n", my_sci,  atof(my_sci)); 
    return 0;
    
}
