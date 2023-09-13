#include <iostream>
#include <cstring>
using namespace std;

char highestOccurringChar(char arr[]) {
    int frequency[256];
    for (int i=0 ; i<256 ; i++){
        frequency[i]=0;
    }
    for (int i=0 ; arr[i]!='\0' ; i++){
        frequency[arr[i]]++;
    }
    int max=-1;
    char highestOccurringChar;
    for (int i=0 ; i<256 ; i++){
        if (frequency[i]>max){
            max=frequency[i];
            highestOccurringChar=i;
        }
    }
    return highestOccurringChar;
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << highestOccurringChar(str);
}

/*alt:-
char highestOccurringChar(char arr[]) {
    int frequency[26];
    for (int i=0 ; i<26 ; i++){
        frequency[i]=0;
    }
    for (int i=0 ; arr[i]!='\0' ; i++){
        frequency[arr[i]-'a']++;
    }
    int max=-1;
    char highestOccurringChar;
    for (int i=0 ; i<26 ; i++){
        if (frequency[i]>max){
            max=frequency[i];
            highestOccurringChar=i+'a';
        }
    }
    return highestOccurringChar;
}*/