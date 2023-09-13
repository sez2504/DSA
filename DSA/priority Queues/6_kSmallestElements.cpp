#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> kSmallest(int arr[], int n, int k) {
    vector<int> v;
    if (n==0){
        return v;
    }
    int largest = arr[0];
    int largestIndex=0;
    int secondLargestIndex=1;
    for (int i=0; i<k ; i++){
        v.push_back(arr[i]);
        if (arr[i]>largest){
            largest=arr[i];
            largestIndex=i;
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
        if (arr[i]<largest){
            //cout<<"largestIndex : "<<largestIndex<<endl;
            v[largestIndex]=arr[i];
            largest=v[0];
            largestIndex=0;
            for (int j=1 ; j<k ; j++){
                if (v[j]>largest){
                    largest=v[j];
                    largestIndex=j;
                    //secondLargestIndex=largestIndex;
                }
            }
            //cout<<"largestIndex : "<<largestIndex<<endl;
        }
    }

    
    return v;

}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kSmallest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    delete[] input;
}