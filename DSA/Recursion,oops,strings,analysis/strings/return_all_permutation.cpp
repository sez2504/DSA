#include <iostream>
#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
    if (input.size()==1){
        output[0]=input;
        return 1;
    }
   	if (input.size()==0){
           return 0;
       }
    int smalloutput=returnPermutations(input.substr(1),output);
    int stringlen = output[0].size();
    for (int i=1 ; i<=stringlen ; i++){
        for (int j=0 ; j<smalloutput ; j++){
            output[j+i*smalloutput]=output[j];
        }
    }
    int i = 0;
    for (int j=0 ; j<stringlen+1 ; j++){
        for (int k=0 ; k<smalloutput ; k++){
            output[k+j*smalloutput]=input[0]+output[k+j*smalloutput];
            for (int l=0 ; l<i ; l++){
                char temp = output[k][l+1];
                output[k+j*smalloutput][l+1] = output[k+j*smalloutput][l];
                output[k+j*smalloutput][l]=temp;
            }
        }
        i++;
    }
    //cout<<smalloutput<<endl;
    return (stringlen+1)*smalloutput;
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
