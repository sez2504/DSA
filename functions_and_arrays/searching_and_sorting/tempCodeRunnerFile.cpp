#include <iostream>
using namespace std;

void createArray(int arr[100] , int n){
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
    cin>>n;
    int arr[100];
    createArray(arr,n);
    for (int i = 1 ; i <n ; i++){
            arr[i-1]=arr[i];
        }
    printArray(arr,n);
    return 0;
}