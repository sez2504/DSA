#include <iostream>
using namespace std;

inline int max(int a , int b){ //only for 1 line functions , takes no memory space like preprocessors , avoid func call overhead
    return (a>b)?a:b;
}

int main()
{
    int c=max(5,3);
    cout<<c<<endl;
    return 0;
}