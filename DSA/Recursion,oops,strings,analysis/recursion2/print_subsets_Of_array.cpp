#include <iostream>
using namespace std;

void printSubsetsOfArray(int input[],int size, int output[],int outputSize){
    if(size == 0){
        for(int i=0;i<outputSize;i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    
    printSubsetsOfArray(input+1,size-1,output,outputSize);
    //assuming current elemnet is included in array
    int newoutput[20] = {};
    for(int i=0;i<outputSize;i++){
        newoutput[i] = output[i];
    }
    newoutput[outputSize] = input[0];
    printSubsetsOfArray(input+1,size-1,newoutput,outputSize+1);
}

void printSubsetsOfArray(int input[], int size) {
    int ans[20] = {};
    printSubsetsOfArray(input,size,ans,0);
}

/*alt:-
void printSubsetsOfArray_helper(int input[],int si ,int size, int output[],int outputSize){
    if(si == size){
        for (int i=0 ; i<outputSize ; i++){
            cout << output[i] << " ";
        }
        cout <<endl;
        return;
    }
    int smalloutput[40] , smalloutputsize=0;
    printSubsetsOfArray_helper(input ,  si+1,  size, output,  outputSize);

    int i;
    for (i=0 ; i<outputSize ; i++){
        smalloutput[i]=output[i];
    }
    smalloutput[i]=input[si];
   
    printSubsetsOfArray_helper(input ,  si+1,  size, smalloutput,  outputSize+1);
}

void printSubsetsOfArray(int input[], int size) {
    int output[1000];
    printSubsetsOfArray_helper(input,0,size,output,0);
}*/

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
