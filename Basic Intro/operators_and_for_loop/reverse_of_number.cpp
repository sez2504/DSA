#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int rev = 0;
	while (n){
		int remainder = n%10;
		rev=rev*10+remainder;
		n/=10;
	}
	cout<<rev;
}