#include <iostream>
using namespace std;

#include <unordered_map>

int highestFrequency(int arr[], int n) {
    unordered_map<int,int> ourMap;
    int max = arr[0];
    for (int i=0 ; i<n ; i++){
        ourMap[arr[i]]++;
    }
    for (int i=1 ; i<ourMap.size() ; i++){
        if (ourMap[arr[i]]>ourMap[max]){
            max=arr[i];
        }
    }
    return max;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}