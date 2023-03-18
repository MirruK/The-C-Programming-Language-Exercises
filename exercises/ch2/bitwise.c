#include <stdio.h>

int setbits(int x,int p,int n,int y){
    // 1. mask x with ones shifted left by n
    // 2. get n rightmost bits from y (getbits function)
    // 3. or mask x with y

    x = (x & (~0 << n));          // step 1.
    y = (y >> (p+1-n)) & ~(~0 << n); // step 2.
    x = x | y;                       // step 3.
    return x;
}

int invert(int x,int p,int n){
    // 1. Create mask y of ones for bits from p through p+n
    // 2. xor mask x with y

    int y = (~(~0 << n)) << (p+1-n); // step 1.
    x = x ^ y;                       // step 2.
    return x;
}

// TODO: This is for Exercise 2-8
// ... it doesn't work
int rightrot(int x, int n, int c){
    // Make x into an array of bits
    // Make another array of the same size
    // Rearrange indeces by (x+n) % length(x)
    int length = c;
    int bits[length], copy[length];
    for(int i = 1; i<length+1; ++i){
        printf("Creating bits arr\nCurr: %b\n", (x & (0b1<<(length-i)))>0);
        bits[i-1] = (x & (0b1<<(length-i)))>0;    
    }
    for(int i = 0; i<length; ++i){
        copy[i] = bits[((i+n) % length)];
        printf("Copy index %d = %d\n", i, copy[i]);
    }
    for(int i = 0; i<length; ++i){
        x = x | (copy[i]<<(length-i));
    }
    return x;
}

// Exercise 2-9...:

int main(){
    int bits1 = 0b10010011;
    int setby = 0b11111001;
    int rot =   0b10001100;
    printf("Bits before setting: %b\n", bits1);
    printf("Setting by mask: %b\n", setby);
    bits1 = setbits(bits1,3,4,setby);
    printf("After setting: %b\n", bits1);
    printf("bits1 middle 3 bits inverted: %b\n", invert(bits1,5,3));
    printf("bits1 all bits inverted: %b\n", invert(bits1,7,8));
    printf("Rot: %b rotated right by 3 to: %b\n", rot, rightrot(rot, 3, 8));
    return 0;
}
