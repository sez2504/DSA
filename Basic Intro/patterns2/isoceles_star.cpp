#include<iostream>
using namespace std;


int main(){
	int n;
	cin >> n;
	int i = 1 ;
	while (i<=n) {
		int j = 1;
        int spaces = n-i;
        while(spaces>=1){
            cout << " ";
            spaces--;
        }
		while (j<=i){
			cout << "*"; 
			j++;
		}
        j=i-1;
        while (j>=1)
        {
            cout << "*";
            j--;
        }
		cout << endl;
		i++;
	}
}
