#include <iostream>
#include <vector>
using namespace std;

int kthLargest(int* arr, int n, int k) {
    vector<int> v;
    // if (n==0){
    //     return v;
    // }
    int smallest = arr[0];
    int smallestIndex=0;
    //int secondLargestIndex=1;
    for (int i=0; i<k ; i++){
        v.push_back(arr[i]);
        if (arr[i]<smallest){
            smallest=arr[i];
            smallestIndex=i;
            //cout<<"largest : "<<largest<<endl;
            //secondLargestIndex=largestIndex;
        }
    }

    // for (int i=0 ; i<k ; i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    
    for (int i=k ; i < n ; i++){
        // for (int i=0 ; i<k ; i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        if (arr[i]>smallest){
            //cout<<"largestIndex : "<<largestIndex<<endl;
            v[smallestIndex]=arr[i];
            smallest=v[0];
            smallestIndex=0;
            for (int j=1 ; j<k ; j++){
                if (v[j]<smallest){
                    smallest=v[j];
                    smallestIndex=j;
                    //secondLargestIndex=largestIndex;
                }
            }
            //cout<<"largestIndex : "<<largestIndex<<endl;
        }
    }    
    return smallest;
}

/*alt:-
#include <queue>

int kthLargest(int* arr, int n, int k) {
    priority_queue<int , vector<int> , greater<int> > minHeap;
   
    for (int i=0; i<k ; i++){
        minHeap.push(arr[i]);
    }
    
    for (int i=k ; i < n ; i++){
        if (arr[i]>minHeap.top()){
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }
    
    return minHeap.top();
}*/

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << kthLargest(arr, n, k);

    delete[] arr;
}