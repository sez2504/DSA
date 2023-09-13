#include<iostream>
using namespace std;


int main(){
	int n;
	cin >> n;
	int i = 1 ;
	while (i<=n) {
		int j = 1;
        int spaces = 1;
        while (spaces <= n-i){
            cout << " ";
            spaces++;
        }
		while (j<=i){
			cout << j; 
			j++;
		}
		cout << endl;
		i++;
	}
}