#include <iostream>
using namespace std;

void printnum(int n){
    for (int i = 1 ; i<=n ; i++){
        cout<<i<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    printnum(n);

    return 0;
}