//Given a number N, print sum of all even numbers from 1 to N.

#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int sum = 0;
	int i = 0;
	while (i<=n) {
		sum+=i;
		i+=2;
	}
	cout << sum;
}