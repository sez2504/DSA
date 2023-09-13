#include <iostream>
using namespace std;

int factorial(int n){
    if (n==0){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}

int factorial_PMI(int n){
    if (n==0){ //base case
        return 1;
    }
    int smallOutput = factorial(n-1); //assume true for n-1.
    int output = n*smallOutput; //apply for n
    return output;
}

int main()
{
    int n;
    cin >> n;
    cout<<factorial(n)<<endl;
    cout<<factorial_PMI(n)<<endl;
    return 0;
}