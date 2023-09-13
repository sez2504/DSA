#include<iostream>
using namespace std;

int main() {
	long sqrt=0;
	long n ;
	cin >> n;
	
	if (n!=0){
		for (long i = n ; i>0 ;i--){
		if (i*i<=n){
			sqrt=i;
			break;
		}
	   }
	}
	
	cout << sqrt <<endl;
}