#include <iostream>
#include <vector>
using namespace std;
#include <unordered_map>

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    unordered_map<int,bool> myMap;
    vector<int> ans;
    for (int i=0 ; i< n ; i++){
        myMap[arr[i]]=false;
    }
    //cout<<myMap.count(70)<<endl;
    int largest = 0;
    if (n==0){
        return ans;
    }
    int start=arr[0];
    //myMap[arr[0]]=true;
    largest++;
    //cout<<myMap.count(arr[0])<<endl;
    for (int i=0 ; i<n ; i++){
        int len = 1;
        int curr = arr[i];
        int temp = curr;
        //cout<<"i : "<<i<<" largest : "<<largest<<endl;
        if(myMap[arr[i]]==true){
            continue;
        }
        myMap[arr[i]]=true;
        while(myMap.count(temp+1)>0){
            len++;
            temp++;
            myMap[temp]=true;
        }
        if (len>largest){
            start=curr;
            largest=len;
        }
        // len = 1;
        // while(myMap.count(curr-1)>0){
        //     len++;
        //     curr--;
        //     myMap[temp]=true;
        // }
        // if (len > largest){
        //     start=curr;
        //     largest=len;
        // }
    }

    int end = start + largest-1;

    ans.push_back(start);
    ans.push_back(end);

    return ans;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}
