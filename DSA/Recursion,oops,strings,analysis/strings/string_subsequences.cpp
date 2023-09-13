#include <iostream>
#include <cmath>
using namespace std;

int subsequences (string input , string output[]){
    if (input.empty()){
        output[0]="";
        return 1;
    }
    string smallerInput = input.substr(1);
    int smallerOutputSize = subsequences(smallerInput,output);
    for (int i = 0 ; i<smallerOutputSize ; i++){
        output[i+smallerOutputSize]=input[0]+output[i];
    }
    return 2*smallerOutputSize;
}

int main()
{
    string input;
    getline(cin , input);
    int a = pow(2,input.size());
    string * output = new string[a];
    int count = subsequences(input , output);
    for (int i = 0 ; i<count ; i++){
        cout<<output[i]<<endl;
    }
    delete [] output;
    return 0;
}