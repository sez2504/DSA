#include <iostream>
using namespace std;

//dry run for n=2 if not understand.
int subset(int input[], int n, int output[][20]) {
	if (n==1){
        output[0][0]=0;
        output[1][0]=1;
        output[1][1]=input[0];
        cout<<output[1][1]<<endl;
		return 2;
	}
	if (n==0){
        output[0][0]=0;
		return 1;
	}
	int smallans = subset(input+1,  n-1, output);
    //cout<<smallans<<endl;
	for (int i=0 ; i<smallans ; i++){
        //cout<<output[i][0]<<endl;
        output[i+smallans][0]=output[i][0];
        for (int j=1 ; j<=output[i][0] ; j++){
            output[i+smallans][j+1]=output[i][j];
        }
        output[i+smallans][0]++;
        output[i+smallans][1]=input[0];
        //cout<<output[i]<<endl;
    }
	return 2*smallans;
}

int main() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);
  //cout<<size<<endl;
  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
