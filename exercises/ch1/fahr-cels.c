/*
 * Exercises 1.3-1.5
 * */
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 10

void fahr_cels(){
  int fahr = LOWER;
  int cels;
  while(fahr <= UPPER){
    printf("Temperature table\n\n");
    cels = 5*(fahr-32) / 9;
    printf("Fahrenheit: %4d F - Celsius: %4d C\n", fahr, cels);
    fahr = fahr + STEP;
  }
}

// Exercise 1.15
void cels_fahr(){
  int cels = LOWER;
  int fahr;
  while(cels <= UPPER){
    printf("Temperature table\n\n");
    fahr = 9*(cels-32) / 5;
    printf("Celsius: %4d C - Fahrenheit: %4d F\n", cels, fahr);
    cels = cels + STEP;
  }
}

void temps_reverse(){
  int fahr;
  printf("Temperature table\n\n");
  for(int cels=UPPER; cels>=LOWER; cels-=STEP){
    fahr = 9*(cels-32) / 5;
    printf("Celsius: %4d C - Fahrenheit: %4d F\n", cels, fahr);
}
}

int main(){
  //fahr_cels();
  //cels_fahr();
  temps_reverse();
}
