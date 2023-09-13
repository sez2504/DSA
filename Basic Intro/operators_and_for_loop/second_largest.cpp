/*Take input a stream of n integer elements, find the second largest element present.
The given elements can contain duplicate elements as well. If only 0 or 1 element is given,
 the second largest should be INT_MIN ( - 2^31 ).
Input format :

Line 1 : Total number of elements (n)

Line 2 : N elements (separated by space)*/



#include<iostream>
using namespace std;
#include <climits>


int main() {
	int n;
	cin >> n;
	int i,flag;
	int arr[n];
    int temp=0;
    for (i=0; i<n ; i++){
        cin>>arr[i];
	}
    for (int i=0 ; i < n ; i++){
        for (int j = i ; j<n ; j++){
            if (arr[j]>arr[i]){
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
    for (int i = 0 ; i<n-1 ;i++){
        if (arr[i+1]!=arr[i]){
            flag=0;
            cout<<arr[i+1]<<endl;
            break;
        }
        else {
            flag=1;
        }
    }
    if (flag==1||n==1){
        cout << INT_MIN<<endl;
    }
    for (int i = 0 ; i<n ;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}


