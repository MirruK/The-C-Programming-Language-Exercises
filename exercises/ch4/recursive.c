#include <stdio.h>
#include <string.h>

int get_ind(int n){
    int i = 0;
    if (n<0){
       i++; 
       n = -n;
    }
    for(; n>0; i++, n/=10);
    printf("val of i: %d\n", i);
    return i>0 ? i-1 : i;
}

void swap(char s[], int ind1, int ind2){
    int temp = s[ind1];
    s[ind1] = s[ind2];
    s[ind2] = temp;
}

void rec_reverse(char s[], int first, int last){
    if(first>=last) return;
    swap(s, first, last);
    rec_reverse(s, first+1, last-1);
}

void rec_itoa(char buf[], int ind, int input){
    if(input<0){
        buf[0] = '-';
        input = -input;
    }
    buf[ind] = (input % 10) + '0';
    if(input / 10){
        rec_itoa(buf, ind-1, input/10);
    }
}

int main(){
    // char buffer[20];
    // rec_itoa(buffer, get_ind(-1234), -1234);
    // printf("My int as a string: %s\n", buffer);
    //
    char test_str[] = "testt";
    rec_reverse(test_str, 0, strlen(test_str)-1);
    printf("String after reverse: %s\n", test_str);
}
