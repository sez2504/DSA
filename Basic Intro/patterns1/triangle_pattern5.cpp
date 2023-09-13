#include<iostream>
using namespace std;


int main(){
	int n;
	cin >> n;
	int i = 1 ;
	while (i<=n) {
		int j = 1;
		while (j<=i){
			cout << n-j+1; 
			j++;
		}
		cout << endl;
		i++;
	}
}
/* alternate :-
#include<iostream>
using namespace std;


int main(){
	int n;
	cin >> n;
	int i = 1 ;
	while (i<=n) {
		int j = i;
		while (j>=1){
			cout << j; 
			j--;
		}
		cout << endl;
		i++;
	}
}
*/