#include<iostream>
using namespace std;

//n is number of rows , n can only be odd
int main(){
	int n;
	cin >> n;
	int i = 1 ;
    //upper half
	while (i<=(n+1)/2) { //for n = 5 , i<=3
		int j = 1;
        int spaces = n/2-i+1; //at i = 1 , spaces = 2 ; i = 2 , spaces =1
        while(spaces>=1){ //prints two spaces for i = 1
            cout << " ";
            spaces--;
        }
		while (j<=i){ //at i=1 prints one star , two at i =2
			cout << "*"; 
			j++;
		}
        j=i-1; //j = 0 at i = 1 ; j=1 at i=2
        while (j>=1) //no print at i =1 ; prints one star at i =2
        {
            cout << "*";
            j--;
        }
		cout << endl;
		i++;
	}
    //lower half
    i = 1 ;
	while (i<(n+1)/2) { //n<3
		int j = 1;
        int spaces = n/2; //spaces = 2
        while(spaces<n/2+i){//prints i spaces
            cout << " ";
            spaces++;
        }
		while (j<=n/2-i+1){ //j<=2 at i = 1  , j<=1 at i =2
			cout << "*";   //prints 2 stars at i = 1
			j++;            //prints 1 star at i=2
		}
        j=n/2-i; //j = 1 at i = 1 ,j=0 at i = 2
        while (j>=1) //prints one star at i =1 no star at i=2
        {
            cout << "*";
            j--;
        }
		cout << endl;
		i++;
	}
}