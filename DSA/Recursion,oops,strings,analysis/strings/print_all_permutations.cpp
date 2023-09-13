#include <iostream>
#include <string>
using namespace std;

void printPermutations_helper(string input , string output){
    if (input.size()==0){
        cout<<output<<endl;
        return;
    }
    // printPermutations_helper(input.substr(1),output.substr(0,0)+input[0]+output.substr(0));
    // if (output.size()>=1){
    //     printPermutations_helper(input.substr(1),output.substr(0,1)+input[0]+output.substr(1));
    // }
    // if (output.size()>=2){
    //     printPermutations_helper(input.substr(1),output.substr(0,2)+input[0]+output.substr(2));
    // }
    static int inputlen = input.size();
    for (int i=0 ; i<inputlen ; i++){
        if (output.size()>=i){
            printPermutations_helper(input.substr(1),output.substr(0,i)+input[0]+output.substr(i));
        }
    }
}

/*alt:-
void printPermutations_helper(string input , string output){
    if (input.size()==0){
        cout<<output<<endl;
        return;
    }
    for (int i=0 ; i<=output.length() ; i++){
        printPermutations_helper(input.substr(1),output.substr(0,i)+input[0]+output.substr(i));
    }
}*/

void printPermutations(string input){
    string output;
    printPermutations_helper(input,output);
}


int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}