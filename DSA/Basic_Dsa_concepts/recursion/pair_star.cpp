/*Given a string S, compute recursively a new string where identical chars that are adjacent 
in the original string are separated from each other by a "*".*/

#include <iostream>
using namespace std;

int length (char input[]){
    int len=0;
    while (input[len]!='\0'){
        len++;
    }
    return len;
}

void pairStar(char input[]) {
    if (input[0]=='\0'){
        return;
    }
    pairStar(input+1);
    int len = length(input);
    if (input[0]==input[1]){
        input[len+1]='\0';
        for (int i=len-1 ; i>=0 ; i--){
            input[i+1]=input[i];
        }
        cout<<len<<endl;
        //input[3]=input[2];
        cout<<input<<endl;
        input[1]='*';
    }
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
