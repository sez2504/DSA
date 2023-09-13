#include <iostream>
using namespace std;

int main(){
	int n ;
	cin >> n;
	for (int i = 2 ; i<=n ; i++){
		bool divided = false;
		for (int j = 2 ; j < i ; j++){
			if (i%j==0){
				divided = true;
				break;
			}
		}
		if (!divided) {
			cout << i << endl;
		}
	}
}
