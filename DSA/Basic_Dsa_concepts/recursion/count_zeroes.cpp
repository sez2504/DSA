#include <iostream>
using namespace std;

//ignore useless zeroes at start.

int countZeros(int n) {
    if (n<=9){
        if (n==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    int ans = countZeros(n/10);
    if (n%10==0){
        return ans+1;
    }
    return ans; 
}

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
