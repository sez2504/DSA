#include <iostream>
using namespace std;

int fibonacci_helper(int n , int * ans){
    if (n<=1){
        return 1;
    }
    //if op already exists
    if (ans[n]!=-1){
        return ans[n];
    }

    int a = fibonacci_helper(n-1 , ans);
    int b = fibonacci_helper(n-2 , ans);

    //save op for future
    ans[n]=a+b;

    return ans[n];
}

int fibonacci(int n){
    int * ans = new int[n+1];
    for (int i=0 ; i<n ; i++){
        ans[i]=-1;
    }
    return fibonacci_helper(n,ans);
}

int main()
{
    
    return 0;
}