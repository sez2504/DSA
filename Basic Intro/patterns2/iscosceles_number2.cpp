#include<iostream>
using namespace std;


int main(){
	int n;
	cin >> n;
	int i = 1 ;
	while (i<=n) {
		int j = i;
        int spaces = n-i;
        while(spaces>=1){
            cout << " ";
            spaces--;
        }
		while (j<i+i){
			cout << j; 
			j++;
		}
        j=j-2;
        while (j>=i)
        {
            cout << j;
            j--;
        }
		cout << endl;
		i++;
	}
}
