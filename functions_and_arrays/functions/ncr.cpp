#include <iostream>
using namespace std;

long long fact(int a){
    long long  fact=1;
    for (int i = 1 ; i<=a ; i++){
        fact*=i;
    }
    //cout<<fact<<endl;
    return fact;
}

int ncr (int n , int r){
    int ncr;
    ncr=fact(n)/(fact(r)*fact(n-r));
    return ncr;
}

int main()
{
    int n , r;
    cin >> n >> r;
    cout << ncr(n,r) << endl;
    return 0;
}