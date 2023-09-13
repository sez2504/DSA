#include <iostream>
using namespace std;

int increment (int a){
    a++;
    return a;
}

int main()
{
    int n = 10;
    increment(n);
    cout<<n<<endl;
    n=increment(n);
    cout<<n<<endl;
    return 0;
}