/*Write a program that asks the user for a number N and a choice C. And then give them the possibility to choose 
between computing the sum and computing the product of all integers in the range 1 to N (both inclusive).
If C is equal to -
 1, then print the sum
 2, then print the product
 Any other number, then print '-1' (without the quotes)*/

#include<iostream>
using namespace std;

int main() {
	int n , q;
	cin >> n >> q;
	int sum = -1 ;
	if (q==1){
		int i = 1 ;
		sum = 0;
		while (i<=n){
			sum+=i;
            i++;
		}
	}
	else if (q==2){
		int i = 1 ;
		sum = 1;
		while (i<=n){
			sum*=i;
            i++;
		}
	}
	cout << sum;
}
