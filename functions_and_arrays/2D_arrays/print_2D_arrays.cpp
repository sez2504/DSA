/*Given a 2D integer array with n rows and m columns. 
Print the 0th row from input n times, 1st row n-1 times…..(n-1)th row will be printed 1 time.*/

#include <iostream>
using namespace std;

void print2DArray(int **arr, int r, int c) {
	for (int i=0 ; i<r ; i++){
		int no_of_times = r-i;
		while (no_of_times--){
			for (int j = 0 ; j< c ; j++){
				cout << arr[i][j]<<" ";
			}
			cout << endl;
		}
	}
}

int main() {
    int row, col;
    cin >> row >> col;

    int **input = new int*[row];
    for(int i = 0; i < row; i++) {
	    input[i] = new int[col];
	    for(int j = 0; j < col; j++) {
	        cin >> input[i][j];
	    }
    }
    print2DArray(input, row, col);
}
