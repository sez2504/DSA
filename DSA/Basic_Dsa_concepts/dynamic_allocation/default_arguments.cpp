#include <iostream>
using namespace std;

int sum(int a[] , int size , int startIndex=0){ //default value only to rightmost.
    int ans=0;
    for (int i=startIndex ; i<size ; i++){
        ans+=a[i];
    }
    return ans;
}

int main()
{
    int a[20];
    for (int i=0 ; i<20 ; i++){
        cin>>a[i];
    }
    cout<<sum(a,20)<<endl;
    return 0;
}