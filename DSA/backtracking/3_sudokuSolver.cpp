#include<iostream>
using namespace std;

int arr[9][9];

bool placeOK(int row , int col , int num){
    for (int i=0 ; i<9 ; i++){
        if (arr[row][i]==num){
            return false;
        }
    }

    for (int i=0 ; i<9 ; i++){
        if (arr[i][col]==num){
            return false;
        }
    }

    int boxRow = row/3;
    int boxCol = col/3;

    for (int i=boxRow*3 ; i<boxRow*3 + 3 ; i++){
        for (int j=boxCol*3 ; j<boxCol*3 + 3 ; j++){
            if (arr[i][j]==num){
                return false;
            }
        }
    }

    return true;
}

// bool rowOk(int row , int col , int num){
//     for (int i=0 ; i<9 ; i++){
//         if (arr[row][i]==num){
//             return false;
//         }
//     }
//     return true;
// }

// bool colOk(int row , int col , int num){
//     for (int i=0 ; i<9 ; i++){
//         if (arr[i][col]==num){
//             return false;
//         }
//     }
//     return true;
// }

// bool boxOk(int row , int col , int num){
//     int boxRow = row%3;
//     int boxCol = col%3;

//     for (int i=boxRow ; i<boxRow*3 + 3 ; i++){
//         for (int j=boxCol ; j<boxCol*3 + 3 ; j++){
//             if (arr[i][j]==num){
//                 return false;
//             }
//         }
//     }
//     return true;
// }

bool sudokuSolved(int row , int col){
    // if (ans==true){
    //     return true;
    // }
    if (row==9){
        //cout<<endl;
        //ans=true;
        return true;
    }
    if (col==9){
        // for (int i=0 ; i<9 ; i++){
        //     // for (int j=0 ; j<9 ; j++){
        //     //     cout<<arr[i][j]<<" ";
        //     // }
        //     // cout<<endl;
        //     cout<<arr[row][i]<<" ";
        // }
        // cout<<endl;
        return sudokuSolved(row+1,  0);
    }
    if(arr[row][col]!=0){
        return sudokuSolved(row ,  col+1);
    }
    for (int num = 1; num <= 9; num++) {
        if (placeOK(row, col, num)) {
            //cout<<"Num in ok : "<<num<<"row : "<<row<<"col : "<<col<<endl;
            arr[row][col] = num;  // Place the number.
            if (sudokuSolved(row, col + 1)) {
                return true;  // Continue solving the rest of the puzzle.
            }
            arr[row][col] = 0;  // If placing 'num' doesn't lead to a solution, backtrack.
        }
    }
    return false;
}

int main(){
    for (int i=0 ; i<9 ; i++){
        for (int j=0 ; j<9 ; j++){
            cin>>arr[i][j];
        }
    }
    if (sudokuSolved(0 ,  0)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}