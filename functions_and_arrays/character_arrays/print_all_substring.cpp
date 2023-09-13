#include <iostream>
#include <cstring>
using namespace std;

void printSubstrings(char input[]) {
    for (int k=0 ; input[k]!='\0' ;k++){
        for (int i=k ; input[i]!='\0' ; i++){
            for (int j=k ; j<i+1 ; j++){
                cout << input[j];
            }
            cout << endl;
        }
    }
        
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    printSubstrings(str);
}