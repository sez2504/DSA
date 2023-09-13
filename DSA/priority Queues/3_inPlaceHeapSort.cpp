#include <iostream>

void heapSort_helper(int * arr , int n ){
    if (n==0){
        return;
    }
    for(int i=1 ; i<n ; i++){      
        int childIndex = i;
        int parentIndex = (i-1)/2;
        while (childIndex>0){
            if (arr[parentIndex]>arr[childIndex]){
                int temp = arr[parentIndex];
                arr[parentIndex]=arr[childIndex];
                arr[childIndex]=temp;
                childIndex=parentIndex;
                parentIndex=(childIndex-1)/2;
            }
            else{
                break;
            }
        }
    }
    // for (int i=0 ; heapSize>0 ; heapSize--){
    //     if (heapSize==1){
    //         break;
    //     }
    //     int temp = arr[0];
    //     arr[0]=arr[heapSize-1];
    //     arr[heapSize-1]=temp;
    //     int parentIndex=0;
    //     int child1=1;
    //     int child2=2;
    //     while (child1<heapSize-1){
    //         if (child1==heapSize-2){
    //             if (arr[parentIndex]>arr[child1]){
    //                 int temp = arr[parentIndex];
    //                 arr[parentIndex]=arr[child1];
    //                 arr[child1]=temp;
    //            }
    //            break;
    //         }
    //         int minIndex ;
    //         if (arr[child1]<arr[child2]){
    //             minIndex=child1;
    //         }
    //         else{
    //             minIndex=child2;
    //         }
    //         if(arr[parentIndex]>arr[minIndex]){
    //             int temp = arr[parentIndex];
    //             arr[parentIndex]=arr[minIndex];
    //             arr[minIndex]=temp;
    //             parentIndex=minIndex;
    //             child1=2*minIndex+1;
    //             child2=2*minIndex+2;
    //         }
    //         else{
    //             break;
    //         }
    //     }
    // }
}

using namespace std;

void removeMin(int * arr , int heapSize , int n){
    for (int i=0 ; heapSize>0 ; heapSize--){
        if (heapSize==1){
            break;
        }
        int temp = arr[0];
        arr[0]=arr[heapSize-1];
        arr[heapSize-1]=temp;
        int parentIndex=0;
        int child1=1;
        int child2=2;
        while (child1<heapSize-1){
            if (child1==heapSize-2){
                if (arr[parentIndex]>arr[child1]){
                    int temp = arr[parentIndex];
                    arr[parentIndex]=arr[child1];
                    arr[child1]=temp;
               }
               break;
            }
            int minIndex ;
            if (arr[child1]<arr[child2]){
                minIndex=child1;
            }
            else{
                minIndex=child2;
            }
            if(arr[parentIndex]>arr[minIndex]){
                int temp = arr[parentIndex];
                arr[parentIndex]=arr[minIndex];
                arr[minIndex]=temp;
                parentIndex=minIndex;
                child1=2*minIndex+1;
                child2=2*minIndex+2;
            }
            else{
                break;
            }
        }
    }
}

void heapSort(int arr[], int n) {
    heapSort_helper(arr,  n );
    removeMin(arr ,  n , n);
}

using namespace std;

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}