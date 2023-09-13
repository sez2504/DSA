#include <iostream>
#include <vector>
using namespace std;

#include <queue>

int buyTicket(int *arr, int n, int k) {
    priority_queue<int> maxHeap;
    int flag=0;
    int element = arr[k];
    for (int i=0 ; i<n ; i++){
        // if (arr[i]==element && i!=k){
        //     flag++;
        // }
        maxHeap.push(arr[i]);
    }
    int time = 0;
    int duplicae_deleted = 0;
    int index=0;
    while (!maxHeap.empty()){
        // if (maxHeap.top()==element && duplicae_deleted==flag){
        //     time++;
        //     break;
        // }
        // else{
        //     if (maxHeap.top()==element){
        //         duplicae_deleted++;
        //     }
        //     maxHeap.pop();
        //     time++;
        // }
        if (arr[index]==maxHeap.top()){
            if (index==k){
                time++;
                break;
            }
            index++;
            time++;
            maxHeap.pop();
        }
        else{
            int item = arr[index];
            for (int j=index ; j<n ; j++){
                arr[j]=arr[j+1];
            }
            arr[n-1]=item;
            k--;
            if (k==index-1){
                k=n-1;
            }
        }
        // for (int i=0 ; i<n ; i++){
        //     cout<<arr[i]<<' ';
        // }
        // cout<<" time : "<<time<<" k : "<<k<<" index : "<<index;
        // cout<<endl;
    }
    return time;
}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}