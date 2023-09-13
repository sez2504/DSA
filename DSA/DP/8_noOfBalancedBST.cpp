#include <iostream>
using namespace std;

#define MOD 1000000007

int balancedBTs(int n) {
    if (n==0 || n==1){
        return 1;
    }
    // if (n==1){
    //     return 1;
    // }
    long long int opt1 = balancedBTs(n-1);
    long long int opt2 = balancedBTs(n-2);

    long long int caseEqualHeight = opt1*opt1;
    long long int caseLeftHigher = opt1*opt2;
    long long int caseRightHigher = caseLeftHigher;

    long long int ans = caseLeftHigher+caseRightHigher+caseEqualHeight;
    return ans%MOD;
}

/*MEMORIZATION:-

#define MOD 1000000007

int balancedBTs_helper(int n , int * ans){
    if (n==0 || n==1){
        return 1;
    }
    // if (n==1){
    //     return 1;
    // }
    if (ans[n]!=-1){
        return ans[n];
    }
    long long int opt1 = balancedBTs_helper(n-1,ans);
    long long int opt2 = balancedBTs_helper(n-2,ans);

    long long int caseEqualHeight = opt1*opt1;
    long long int caseLeftHigher = opt1*opt2;
    long long int caseRightHigher = caseLeftHigher;

    ans[n] = (caseLeftHigher+caseRightHigher+caseEqualHeight)%MOD;
    return ans[n];
}

int balancedBTs(int n) {
    int * ans = new int[n+1];
    for (int i=0 ; i<n+1 ; i++){
        ans[i]=-1;
    }
    return balancedBTs_helper(n , ans);
}*/

/*DP:-
int balancedBTs(int n) {
    long long int *ans = new long long int[n + 1];
    ans[0] = ans[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        ans[i] = (ans[i - 1] * ans[i - 1] % MOD + 2 * ans[i - 1] * ans[i - 2] % MOD) % MOD;
    }
    
    long long int result = ans[n];
    delete[] ans; // Don't forget to free the allocated memory.
    
    return result;
}*/

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}