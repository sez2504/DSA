#include <iostream>
using namespace std;

void printSubsetSumToK(int input[], int size, int k , int output [] , int outputsize) {
    if (0==size){
        if (k==0){
            for (int i=0 ; i<outputsize ; i++){
                cout << output[i] <<" ";
            }
            cout<<endl;
            return;
        }
        else{
            return;
        }
    }

    printSubsetSumToK(input+1 ,  size-1,  k,  output,  outputsize);
    int newoutput[20];
    for(int i=0;i<outputsize;i++){
        newoutput[i] = output[i];
    }
    newoutput[outputsize] = input[0];
    printSubsetSumToK(input+1,  size-1, k-input[0], newoutput, outputsize+1);
}

void printSubsetSumToK(int input[], int size, int k) {
    int output[20];
    printSubsetSumToK(input,  size,  k, output,  0);
}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
