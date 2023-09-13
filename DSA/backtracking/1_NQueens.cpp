#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int arr[11][11];

bool isOK(int n , int row , int col){
    //same column
    for (int i=row-1 ; i>=0 ; i--){
        if (arr[i][col]==1){
            return false;
        }
    }
    //same upper right diagonal 
    //cant be lower as we have not inserted a value there yet
    for (int i=row-1 ,  j=col+1 ; i>=0 && j<n ; i-- , j++){
        if (arr[i][j]==1){
            return false;
        }
    }
    //same upper left diagonal 
    for (int i=row-1 ,  j=col-1 ; i>=0 && j>=0 ; i-- , j--){
        if (arr[i][j]==1){
            return false;
        }
    }

    return true;
}

vector<vector<int> > nQueens_helper(int n , int row , vector<vector<int> > v){
    if (n==0){
        return v;
    }
    if (row==n){
        //we have reached some solution
        vector<int> smallAns;
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                smallAns.push_back(arr[i][j]);
            }
        }
        v.push_back(smallAns);
        //delete [] smallAns;
        return v;
    }
    
    for (int i=0 ; i<n ; i++){
        if (isOK(n,  row ,  i)){
            arr[row][i]=1;
            v=nQueens_helper(n, row+1 ,  v);
            arr[row][i]=0;
        }
    }

    return v;
}

vector<vector<int> > nQueens(int n)
{
    vector<vector<int> > v;
    // vector<int> currentAns;
    // for (int i=0 ; i<n*n ; i++){
    //     currentAns.push_back(0);
    // }
    // vector<bool> isOK;
    // for (int i=0 ; i<n*n ; i++){
    //     isOK.push_back(true);
    // }
    memset(arr , 0 , n*n*sizeof(int));
    return nQueens_helper(n, 0 ,  v);
}

class Runner
{
    int n;

public:
    
    void takeInput()
    {
        cin >> n;
    }
    void execute()
    {
        auto ans = nQueens(n);
    }
    void executeAndPrintOutput()
    {
        auto ans = nQueens(n);
        if(ans.size())
        {
            sort(ans.begin(),ans.end());
            for(auto v:ans)
            {
                for(auto i:v)cout << i << " ";
                cout << endl;
            }
        }
        else cout << "\'No Configuration\'";
    }
};

int main()
{
        Runner runner;
        runner.takeInput();
        runner.executeAndPrintOutput();   
    return 0;
    
}