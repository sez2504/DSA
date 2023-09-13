#include <iostream>
#include <cstring>
using namespace std;

bool checkPalindrome(char str[]) {
    int i=0;
    while(str[i]!='\0'){
        i++;
    }//i is length of string
    for (int j=0 ; j<i/2 ; j++){
        if (str[j]!=str[i-j-1]){
            return false;
            break;
        }
    }
    return true;
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << (checkPalindrome(str) ? "true" : "false");
}