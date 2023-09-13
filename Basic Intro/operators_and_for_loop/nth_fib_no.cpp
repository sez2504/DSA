#include<iostream>
using namespace std;

int main()
{
        int f1 = 1 , f2=1 , temp,n;
        cin>>n;
        for (int i =1 ; i<n ; i++){
                temp=f1;
                f1=f2;
                f2+=temp;
        }
        cout << f1 << endl;
}