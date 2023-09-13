#include <iostream>
using namespace std;

#include <unordered_map>
#include <vector>

vector<int> removeDuplicates (int * a , int size){
    vector<int> output;
    unordered_map<int,bool> seen;
    for (int i=0 ; i<size ; i++){
        if (seen.count(a[i])>0){
            continue;
        }
        seen[a[i]]=true;
        output.push_back(a[i]);
    }
    return output;
}

void printIntersection(int *input1, int *input2, int size1, int size2)
{
    unordered_map<int , int> map1;
    unordered_map<int , int> map2;
    int size_max ;// size_min;
    if (size1>size2){
        size_max=size1;
        //size_min=size2;
    }
    else{
        size_max=size2;
        //size_min=size1;
    }
    for (int i=0 ; i<size_max ; i++){
        if (i<size1){
            map1[input1[i]]++;
        }
        if (i<size2){
            map2[input2[i]]++;
        }
    }
    //int min_map_size;
    bool map1_min = true;
    if (map1.size()>map2.size()){
        //min_map_size=map2.size();
        map1_min=false;
    }
    // else{
    //     min_map_size=map1.size();
    // }
    if (map1_min){
        vector<int> mapArray = removeDuplicates(input1,  size1);
        for (int i=0 ; i<map1.size() ; i++){
            int element = mapArray[i];
            if (map1[element]<map2[element]){
                for (int i=0 ; i<map1[element] ; i++){
                    cout<<element<<endl;
                }
            }
            else{
                for (int i=0 ; i<map2[element] ; i++){
                    cout<<element<<endl;
                }
            }
        }
    }
    else{
        vector<int> mapArray = removeDuplicates(input2,  size2);
        for (int i=0 ; i<map2.size() ; i++){
            int element = mapArray[i];
            if (map2[element]<map1[element]){
                for (int i=0 ; i<map2[element] ; i++){
                    cout<<element<<endl;
                }
            }
            else{
                for (int i=0 ; i<map1[element] ; i++){
                    cout<<element<<endl;
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    int* arr1 = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int* arr2 = new int[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}