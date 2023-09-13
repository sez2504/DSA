#include <iostream>
using namespace std;

int main()
{
    char input[1000];
    char a[10] , b[1000];
    cin.getline(input,1000); //taakes 999 chars
    cout<<input<<endl;
    cin.getline(a,3); //third arg delimeter is optional by default it is \n
    cout<<a<<endl;
    cin.getline(b,100,'o');
    cout<<b<<endl;
    return 0;
}