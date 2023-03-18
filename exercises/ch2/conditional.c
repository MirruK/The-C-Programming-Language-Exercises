#include <stdio.h>
#include <time.h>

char to_lower(char c){
    return (c - 'A') < 26 ? (c + ('a' - 'A')) : c;
}

int binsearch(int x, int v[], int n){
    int low, high, mid;
    low = 0;
    high = n - 1;
    while(low<=high){
        mid = (low+high)/2;
        if(x<v[mid]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    if(x == v[low-1]){
        return mid;
    }
    return -1;
}

void test_search(){
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    clock_t t = clock();
    binsearch(1, arr, 9);
    t = clock() - t;
    printf("Time to run binsearch %f seconds\n", (double)t/CLOCKS_PER_SEC);
}

void escape(char* s, char* t);

int main(){
    printf("%c\n",to_lower('M'));
    test_search();
    return 0;
}
