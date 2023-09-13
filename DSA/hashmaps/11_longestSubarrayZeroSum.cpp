#include <iostream>
using namespace std;

//continuous subset

#include <unordered_map>

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    int longest = 0;
    int sum = 0;
    unordered_map<int , int> myMap;
   for (int i=0 ; i<n ; i++){
       sum+=arr[i];
       if (sum==0){
           longest=i+1;
           continue;
       }
       if (myMap.count(sum)>0){
           int len = i-myMap[sum];
           if (len>longest){
               longest=len;
           }
           continue;
       }
       myMap[sum]=i;
   }
   return longest;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}