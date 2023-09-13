/*Write a program to print first x terms of the series 3N + 2 which are not multiples of 4.*/

#include<iostream>
using namespace std;

int main() {
	int x;
	cin >> x;
	int i = 1;
	int  j = 5;
	while (j>=0){
		if (j%4!=0){
			i++;
			cout << j << ' ';
		}
		if (i==x+1) {
			break;
		}
		j+=3;
	}
}