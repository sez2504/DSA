#include <iostream>
#include <string>
using namespace std;

string getstring(int d){
    switch (d){
        case 2:
            return "abc";
        case 3:
            return "def";  
        case 4:
            return "ghi";    
        case 5:
            return "jkl"; 
        case 6:
            return "mno"; 
        case 7:
            return "pqrs"; 
        case 8:
            return "tuv"; 
        case 9:
            return "wxyz"; 
        default:
            return " ";
    }
}

void reverse_string_helprer(string output){
    int n = output.length();
    for (int i=0 ; i<n/2 ; i++){
        char temp = output[i];
        output[i]=output[n-i-1];
        output[n-i-1]=temp;
    }
    cout<<output<<endl;
    return;
}

void printKeypad_helper(int num , string output){
    if (num==0){
        reverse_string_helprer(output);
        return;
    }
    string options = getstring(num%10);
    for (int i=0 ; i<options.length() ; i++){
        printKeypad_helper(num/10,output+options[i]);
    }
}

void printKeypad(int num) {
    string output="";
    printKeypad_helper(num,  output);
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);
    string a = "hello";
    reverse_string_helprer(a);
    cout<<a<<endl;
    return 0;
}
