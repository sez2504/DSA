#include <iostream>
using namespace std;

#include <queue>

void findMedian(int *arr, int n)
{
    priority_queue <int , vector<int> , greater<int> > minHeap;
    priority_queue <int> maxHeap;
    //int elements=0;
    for (int i=0 ; i<n ; i++){
        if (maxHeap.size()==0){
            maxHeap.push(arr[i]);
        }
        else if (arr[i]<maxHeap.top()){
            maxHeap.push(arr[i]);
            int max_size=maxHeap.size();
            int min_size=minHeap.size();
            if (max_size-min_size==2){
                int element = maxHeap.top();
                maxHeap.pop();
                minHeap.push(element);
            }
        }
        else{
            minHeap.push(arr[i]);
            int max_size=maxHeap.size();
            int min_size=minHeap.size();
            if (max_size-min_size==-2){
                int element = minHeap.top();
                minHeap.pop();
                maxHeap.push(element);
            }
        }
        if (i%2==0){
            if (maxHeap.size()>minHeap.size()){
                cout<<maxHeap.top()<<" ";
            }
            else{
                cout<<minHeap.top()<<" ";
            }
        }
        else{
            cout<<(maxHeap.top()+minHeap.top())/2<<" ";
        }
    }
    cout<<endl;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}
