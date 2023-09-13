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

    int boxRow = row%3;
    int boxCol = col%3;

    for (int i=boxRow ; i<boxRow*3 + 3 ; i++){
        for (int j=boxCol ; j<boxCol*3 + 3 ; j++){
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

bool sudokuSolved(int row , int col , int num , bool ans){
    if (ans==true){
        return true;
    }
    if (row==10){
        cout<<endl;
        ans=true;
        return true;
    }
    if (col==10){
        for (int i=0 ; i<9 ; i++){
            // for (int j=0 ; j<9 ; j++){
            //     cout<<arr[i][j]<<" ";
            // }
            // cout<<endl;
            cout<<arr[row][i]<<" ";
        }
        //cout<<endl;
        ans = sudokuSolved(row+1,  0 ,  1 , false);
    }
    if(arr[row][col]!=0){
        ans = sudokuSolved(row ,  col+1 ,  1 , false);
    }
    while ((placeOK(row,col,num))==false){
        num++;
        if (num == 10){
            return false;
        }
    }
    //cout<<"num : "<<num;
    arr[row][col]=num;
    ans = sudokuSolved(row ,  col+1 ,  1 , false);
    arr[row][col]=1;
    return ans;
}

int main(){
    for (int i=0 ; i<9 ; i++){
        for (int j=0 ; j<9 ; j++){
            cin>>arr[i][j];
        }
    }
    if (sudokuSolved(0 ,  0 ,  1 ,  false)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}