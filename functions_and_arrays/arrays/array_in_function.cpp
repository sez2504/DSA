#include <iostream>
using namespace std;

void createArray(int arr[100] , int n){
    cout << sizeof(arr) <<endl; //returns 8 , size of pointer in a function
    for (int i = 0 ; i<n ; i++){
        cin>>arr[i];
    }
}

void printArray(int arr[100],int n){
    for (int i=0 ; i<n ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int n;
    cin >> n;
    int arr[100];
    cout << sizeof(arr) << endl;
    createArray(arr,n);
    printArray(arr,n);
    return 0;
}