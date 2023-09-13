#include<iostream>
using namespace std;
#define MOD 1000000007

long long int staircase_helper(int n , int * ans){
    if (n==0||n==1){
        return 1;
    }
    else if (n==2){
        return 2;
    }
    else if (n==3){
        return 4;
    }
    if (ans[n]!=-1){
        return ans[n];
    }
    long long int opt1=staircase_helper(n-1 , ans);
    long long int opt2=staircase_helper(n-2 , ans);
    long long int opt3=staircase_helper(n-3 , ans);
    ans[n]=(opt1+opt2+opt3)%MOD;
    return (opt1+opt2+opt3)%MOD;
}

long long int staircase(int n){
    int * ans = new int[n+1];
    for (int i=0 ; i<=n ; i++){
        ans[i]=-1;
    }
    return staircase_helper(n, ans);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
       cout<<staircase(n)<<endl; 
    }
    return 0;
}