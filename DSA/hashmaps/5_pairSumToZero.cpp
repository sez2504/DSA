#include <iostream>
using namespace std;

#include <unordered_map>

int pairSum(int *arr, int n) {
	unordered_map<int,int> ourMap;
    //int max = arr[0];
    for (int i=0 ; i<n ; i++){
        ourMap[arr[i]]++;
    }
	int pairs = 0;
	for (int i=0 ; i<n ; i++){
        int element = arr[i];
        if (element==0){
            if (ourMap.count(0)>0){
                pairs += ourMap[0]*(ourMap[0]-1)/2;
                ourMap.erase(0);
            }
            continue;
        }
        int pairElement = -arr[i];
        if (ourMap.count(element)>0){
            pairs += ourMap[element]*ourMap[pairElement];
            ourMap.erase(element);
            ourMap.erase(pairElement);
        }
    }
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}