//check if array is sorted.

#include <iostream>
using namespace std;

bool isSorted(int *arr , int n){
    if (n==1 || n==0){
        return true;
    }
    if (arr[0]>arr[1]){
        return false;
    }
    bool isSmallerSorted=isSorted(arr+1,n-1);
    return isSmallerSorted;
}

int main()
{
    int arr[]={3,4,1,6};
    int arr2[]={1,2,3,4};
    cout<<isSorted(arr,4)<<" "<<isSorted(arr2,4)<<endl;
    return 0;
}