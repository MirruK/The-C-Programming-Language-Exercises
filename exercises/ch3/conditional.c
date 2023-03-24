#include <stdio.h>
#include <time.h>
#include <string.h>

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

void escape(char* s, char* t){
    int tind, sind;
    tind = sind = 0;
    char c = t[0];
    char newline_lit[2] = {'\\','n'};
    char tab_lit[2] = {'\\','t'};
    while(c != '\0'){
        c = t[tind];
        switch(c){
            case '\n':
                memcpy(s+sind, newline_lit, 2); //s+sind is the direct pointer
                sind += 2;
                break;
            case '\t':
                memcpy(s+sind, tab_lit, 2); //s+sind is the direct pointer
                sind += 2;
                break;
            default:
                s[sind] = c;
                sind++;
                break;
        }
        tind++;
        }
    }

void escape_inverse(char* s, char* t){
    int tind, sind;
    tind = sind = 0;
    char c = t[0];
    while(c != '\0'){
        c = t[tind];
        if(c == '\\'){
            switch(t[tind+1]){
                case 'n':
                    s[sind] = '\n';
                    tind += 2;
                    sind += 1;
                    break;
                case 't':
                    s[sind] = '\t';
                    tind += 2;
                    sind += 1;
                    break;
                default:
                    s[sind] = '\\';
                    ++tind;
                    ++sind;
            }
        }
        else{
            s[sind] = c;
            sind++;
            tind++;
        }
    }
}

void expand(char s1[], char s2[])
{
    // Takes a string such as "a-z" in s2 and expands and copies it into s1
    // so s2 = "a-z" means s1 = "abcde...xyz"
    if(s2[0] == '\0') return;
    if(s2[1] == '\0') s1[0] = s2[0], s1[1] = '\0';
    char c, next, prev; // c = current char in string, next and prev are char at prev and next index
    int i; // Keeps track of where we are in the original string
    int j = 0; // Keeps track of where we are in the expanded string
    // Look for pattern symbol + '-' + symbol and generate the string
    for (i = 1, prev=s2[0], c = s2[1], next=s2[2]; next != '\0'; prev=s2[i-1], c=s2[i], next=s2[i+1])
    {
        if (i == 1 && c != '-') s1[0] = prev;
        char cl, ch;
        if (c == '-')
        {
            cl = prev;
            ch = next;
            while (cl <= ch)
            {
                s1[j] = cl;
                j++;
                cl++;
            }
            cl = ch = 0;
            i += 2 ;
        }
        else if (next == '-')
        {
            ++i;
        }
        else {
            s1[j] = c;
            ++j;
            ++i;
            }
    }
    s1[j+1] = '\0';
}

int main(){
    //printf("%c\n",to_lower('M'));
    //test_search();
    // char test_str[] = "My\nString Will explicitly\tshow tabs and\nnewlines.";
    // char buffer[200];
    // char buffer2[200];
    // escape(buffer, test_str);
    // printf("Unmodified input:\n %s\n", test_str);
    // printf("Modified input:\n %s\n", buffer);
    // escape_inverse(buffer2, buffer);
    // printf("Inverted modified input: \n %s\n", buffer2);
    char str[] = "-a-zWord0-9";
    char buffer[100];
    expand(buffer,str);
    printf("Here is your expanded string\n%s\n", buffer);

    return 0;
}
