#include <iostream>
using namespace std;

bool checkPalindrome(char input[]) {
    //cout<<input<<endl;
    int i=0;
    while(input[i]!='\0'){
        i++;
    }
    //cout<<i<<endl;
    if (i==0||i==1){
        return true;
    }
    if (input[0]!=input[i-1]){
        return false;
    }
    input[i-1]='\0';
    bool ans=checkPalindrome(input+1);
    return ans;
}

/*alt:-
int length(char input[]){
    int i=0;
    while(input[i]!='\0'){
        i++;
    }
    return i;
}

bool checkPalindrome_helper(char input[] , int start , int end){
    if (input[0]=='\0'||input[1]=='\0'){
        return true;
    }
    if (start>=end){
        return true;
    }
    if (input[start]==input[end]){
        return checkPalindrome_helper(input, start+1,  end-1);
    }
    else{return false;}
}

bool checkPalindrome(char input[]) {
    int len = length(input);
    return checkPalindrome_helper(input, 0,  len-1);
}
*/

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
