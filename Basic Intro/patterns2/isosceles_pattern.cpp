#include<iostream>
using namespace std;


int main(){
	int n;
	cin >> n;
	int i = 1 ;
	while (i<=n) {
		int j = 1;
        int spaces = n-i+1;
        while(spaces>=1){
            cout << " ";
            spaces--;
        }
		while (j<=i){
			cout << j; 
			j++;
		}
        j=i-1;
        while (j>=1)
        {
            cout << j;
            j--;
        }
		cout << endl;
		i++;
	}
}