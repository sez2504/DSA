/*Write a program to input an integer N and print the sum of all its even digits and sum of all its odd digits separately.
Digits mean numbers, not the places! That is, if the given integer is "13245", even digits are 2 & 4 and odd digits are 1, 3 & 5.*/

#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int sum_odd = 0;
	int sum_even = 0;
	while (n){
		int remainder = n%10;
		if (remainder%2==0){
			sum_even+=remainder;
		}
		else{
			sum_odd+=remainder;
		}
		n=n/10;
	}
	cout << sum_even << " " << sum_odd << endl;
}
