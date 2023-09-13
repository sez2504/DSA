#include <iostream>
using namespace std;
#include <climits>

int main()
{
    int n;
    cin>>n;
    int count=1;
    int num;
    int max = INT_MIN , secondMax=INT_MIN;

    while(count<=n){
        cin>>num;
        if(num>max){
            secondMax=max;
            max=num;
        }
        else if (num > secondMax && num!=max){
            secondMax=num;
        }
        count++;
    }
    cout<<secondMax<<endl;
    return 0;
}