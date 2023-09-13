#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    if (n<=9){
        return n;
    }
    int smallAns=sumOfDigits(n/10);
    int ans = smallAns+(n%10);
    return ans;
}

int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}
