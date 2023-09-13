/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include<iostream>
using namespace std;

// int ans[18][18];

void printSolution (int ** solution , int n){
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cout<<solution[i][j]<<" ";
        }
    }
    cout<<endl;
}

void mazeHelp(int arr[18][18], int n, int row , int col , int ** solution){
    if (row == n-1 && col ==n-1){
        solution[row][col]=1;
        printSolution(solution , n);
        return;
    }
    if (row < 0 || row>=n || col<0 || col>=n || arr[row][col]==0){
		return;
	}
	if (solution[row][col]==1){
		return;
	}
	solution[row][col]=1;
    mazeHelp(arr , n , row-1 , col , solution);
    mazeHelp(arr , n , row+1 , col , solution);
    mazeHelp(arr , n , row , col-1 , solution);
    mazeHelp(arr , n , row , col+1 , solution);
    solution[row][col]=0;
}

void printWays(int arr[18][18] , int n , int row , int col){
    int ** solution = new int*[n];
    for (int i=0 ; i<n ; i++){
        solution[i] = new int[n];
    }
	for (int i=0 ; i<n ; i++){
		memset(solution[i], 0, n*sizeof(int));
	}
    mazeHelp(arr , n, 0  ,0 , solution);
}


int main() {
	//ans[0][0]=1
	int n;
	cin>>n;
	int arr[18][18];
	for (int i=0 ; i<n ; i++){
		for (int j=0 ; j<n ; j++){
			cin>>arr[i][j];
		}
	}
	printWays(arr,  n,  0,  0);
	return 0;
}
