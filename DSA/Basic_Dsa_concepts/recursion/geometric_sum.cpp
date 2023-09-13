/*Given k, find the geometric sum i.e.
1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
using recursion.*/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double geometricSum(int k) {
    if (k==0){
        return 1;
    }
    double smallAns = geometricSum(k-1);
    cout<<smallAns<<endl;
    double ans = 1.0/(pow(2,k))+smallAns;
    return ans;
}

int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}
