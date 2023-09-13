/*Given three values - Start Fahrenheit Value (S), End Fahrenheit value (E) and Step Size (W)
you need to convert all Fahrenheit values from Start to End at the gap of W, into their corresponding Celsius values
 and print the table.*/

#include<iostream>
using namespace std;


int main(){
	float S,E,W;
	cin >> S;
	cin >> E;
	cin >> W;
	while (S<=E){
		cout << S << " " << ((5)*(S-32))/9 << endl;
		S+=W;
	}
}


