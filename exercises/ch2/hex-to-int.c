#include <stdio.h>
#include <math.h>

// Enum 0-9 = 0-9, a-f = 10-15, A-F = 10-15
// Ranges if between '0' and '9' then 'n' - '9'
// if between 'a' and 'c' 'c' - 'a'
// same for capital 'A'-'F'
int convert_char(char c){
    int converted;
    if(c >= '0' && c <= '9'){
        converted = c - '0';
    }
    else if(c >= 'a' && c <= 'z'){ 
        converted = (c - 'a') + 10;
    }
    else if(c >= 'A' && c <= 'Z'){ 
        converted = (c - 'A') + 10;
    }
    else{
        converted = 0;
    }
    return converted;
}

int string_length(const char *str){
    int i = 0;
    char c = str[i];
    while(c != '\0'){
        i++;
        c = str[i];
    }
    return i;
}


int htoi(const char *str){
    int ignore_prefix, i, acc, converted;
    i = acc = converted = 0;
    ignore_prefix = 1;
    char c = str[i];
    int size = string_length(str);
    if(size > 2 && c == '0' && (str[i+1] == 'x' || str[i+1] == 'X')){ignore_prefix = 0;}
    while(c != '\0'){
        if(ignore_prefix || i>1){
        if(size == 0){
            acc += convert_char(c);
        }
        else{
            acc += (int)convert_char(c)*pow(16, size-1);
        }
        }
        printf("Value of size: %d\ni: %d\nc: %c\nacc: %d\n", size, i, c, acc);
        i++;
        size--;
        c = str[i];
    }
    return acc;
}

int main(){ 
    char str[] = "0x4CF\0";
    printf("Hex as string: %s\n", str);
    int hex = htoi(str);
    printf("Hex as int: %d\n", hex);
    return 0;
}
