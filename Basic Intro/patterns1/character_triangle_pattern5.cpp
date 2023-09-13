#include<iostream>
using namespace std;


int main(){
	int n;
	cin >> n;
	int i = 1 ;
	while (i<=n) {
		int j = n-i+1;
		while (j<(n-i+1)+i){
			cout << char(j+64); 
			j++;
		}
		cout << endl;
		i++;
	}
}
