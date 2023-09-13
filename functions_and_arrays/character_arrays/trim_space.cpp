#include <iostream>
#include <cstring>
using namespace std;

void trimSpaces(char arr[]) {
    int nonSpaces=0;
    for (int j=0 ; arr[j]!='\0' ;j++){
        if (arr[j]!=' '){
            int temp = arr[j];
            arr[j]=arr[nonSpaces];
            arr[nonSpaces]=temp;
            nonSpaces++;
        }
    }
    arr[nonSpaces]='\0';
}

int main() {
    char input[1000000];
    cin.getline(input, 1000000);
    trimSpaces(input);
    cout << input << endl;
}

