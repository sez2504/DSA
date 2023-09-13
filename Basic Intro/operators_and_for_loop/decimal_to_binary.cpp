#include <iostream>
using namespace std;

int main()
{
    long n;
    cin >> n;
    long binary = 0;
    long count=0;
    long rev=0;
    while (n)
    {
        int remainder = n%2;
        //eg:- n=2 then remainder = 0 the first time , binary = 0
        //remainder = 1 the second time , binary = 0*10 + 1 = 1
        //if n = 4 then remainder = 0,0,1 respectively and binary = 0,0,1 respectively.
        if (binary==0 && remainder==0){ //this counts the number of 0's before the first 1
            count++;
        }
        binary=binary*10+remainder;
        n/=2;
        //cout<<n<<endl;
    }
    //cout<<binary<<endl;
    while (binary){
		int remainder = binary%10;
		rev=rev*10+remainder;
		binary/=10;
	}
    //cout<<rev<<endl;
    for (int i = 0 ; i < count ; i++){
        rev*=10;
    }
    cout << rev <<endl;
    return 0;
}