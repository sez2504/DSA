#include <iostream>
using namespace std;

int subsetSumToK(int input[] , int n , int si , int output[][50] , int k){
  if (si==n){
    if (k==0){
      output[0][0]=0;
      return 1;
    }
    else {
      return 0;
    }
  }
  int smalloutput1[1000][50] , smalloutput2[1000][50];
  int size1 = subsetSumToK(input , n , si+1 , smalloutput1 , k);
  int size2 = subsetSumToK(input , n , si+1 , smalloutput2 , k-input[si]);
  int row=0;
  for (int i=0 ; i<size1 ; i++){
    for (int j=0 ; j<=smalloutput1[i][0] ; j++){
      output[row][j]=smalloutput1[i][j];
    }
    row++;
  }
  for (int i=0 ; i<size2 ; i++){
    output[row][0]=smalloutput2[i][0]+1;
    output[row][1]=input[si];
    for (int j=1 ; j<=smalloutput2[i][0] ; j++){
      output[row][j+1]=smalloutput2[i][j];
    }
    row++;
  }
  return row;
}

int subsetSumToK(int input[], int n, int output[][50], int k) {
    return subsetSumToK(input , n , 0 , output , k);
}

int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}

