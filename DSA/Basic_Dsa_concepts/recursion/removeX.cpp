#include <iostream>
using namespace std;

void removeX(char str[]) {
    if (str[0]=='\0'){
        return;
    }
    removeX(str+1);
    if (str[0]=='x'){
        for (int i=0 ; str[i]!='\0' ; i++){
            str[i]=str[i+1];
        }
    }
}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}