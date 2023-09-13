#include<iostream>
using namespace std;


int main(){
	int n;
	cin >> n;
	int i = 1 ;
	while (i<=n) {
		int j = i;
		while (j<=n+i-1){
			cout << char(j+64); 
			j++;
		}
		cout << endl;
		i++;
	}
}
/*alternate:-
#include<iostream>
using namespace std;


int main(){
	int n;
	cin >> n;
	int i = 1 ;
	while (i<=n) {
		int j = i;
        char startChar = 'A'+i-1;
		while (j<=n){
            char ch = startChar + j - 1;
			cout << ch; 
			j++;
		}
		cout << endl;
		i++;
	}
}*/