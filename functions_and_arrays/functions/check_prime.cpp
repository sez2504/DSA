#include <iostream>
using namespace std;

bool isPrime(int n){
    if (n<2){
        return false;
    }
    else{
        for (int i = 2 ; i<n ; i++){
            if (n%i==0){
                return false;
                break;
            }
        }
        return true;
    }
}

int main()
{
    int n;
    cin>>n;
    for (int i =2 ; i<=n ; i++){
        if (isPrime(i)){
            cout << i <<endl;
        }
    }
    return 0;
}