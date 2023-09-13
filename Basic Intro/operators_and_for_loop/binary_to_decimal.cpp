#include<iostream>
using namespace std;

int main() {
	int n ;
	cin >> n;
	int count = 0; //keeps track of place value
	int dec=0;
	while (n){
		int remainder =n%10;
		int temp=1;
		if (remainder==1){
			for(int i = 0 ; i<count ; i++){
				temp*=2; //raises 2^placevalue
			}
			dec+=temp;//adds 2^place value to sum if there is 1 at the place and ignores 0
		}
		count++;
		n/=10;
	}
	cout << dec <<endl;
}