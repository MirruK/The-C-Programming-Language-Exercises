#include <stdio.h>

void mut_const(const int arr[]){
  // Yay, neither this nor arr[0] = 1 works
  // Compilern sätter mig på jäähy
  *(arr+sizeof(int)) = 1;
}

int main(){
  const int value[10] = {0};
  printf("Const int value: %d\n", value[0]);
  printf("Const int value after attempted change: %d\n", value[0]);
  return 0;
}
