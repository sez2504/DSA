/*Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. 
Save all the indexes in the output array (in increasing order).
Do this recursively. Indexing in the array starts from 0.
Return the size of the output array*/

#include<iostream>
using namespace std;

int allIndexes(int arr[], int size, int x, int output[]) {
  if (size==0){
    return 0;
  }
  int ans = allIndexes(arr+1, size-1,  x, output);
  for (int i=0 ; i<ans ; i++){
    output[i]++;
  }
  if (arr[0]==x){
    for (int i=ans ; i>=0 ; i--){
      output[i+1]=output[i];
    }
    output[0]=0;
    ans++;
  }
  return ans;
}

/*alt:-
int allIndexes(int arr[], int size, int x, int output[]) {
  if (size==0){
    return 0;
  }
  int ans = allIndexes(arr, size-1,  x, output);
  if (arr[size-1]==x){
    output[ans]=size-1;
    ans++;
  }
  return ans;
}
*/

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}