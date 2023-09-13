#include <iostream>
using namespace std;

bool isMaxHeap_helper(int * arr , int current , int n){
    int parentIndex=current;
    int leftChild=2*current+1;
    int rightChild=2*current+2;
    if (leftChild>n-1){
        return true;
    }
    if (rightChild>n-1){
        if (arr[parentIndex]<arr[leftChild]){
            return false;
        }
        else{
            return true;
        }
    }
    if (arr[parentIndex]<arr[leftChild] || arr[parentIndex]<arr[rightChild]){
        return false;
    }
    return isMaxHeap_helper(arr,  leftChild ,  n)&&isMaxHeap_helper(arr,  rightChild ,  n);
}

bool isMaxHeap(int arr[], int n) {
    return isMaxHeap_helper(arr, 0 , n);
}

/*alt:-
bool isMaxHeap(int arr[], int n) {
    for (int i=0 ; 2*i+1<n ; i++){
        int leftChild=2*i+1;
        int rightChild=leftChild+1;
        if (arr[i]<arr[leftChild] || arr[i]<arr[rightChild]){
            return false;
        }
    }
    return true;
}*/

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}