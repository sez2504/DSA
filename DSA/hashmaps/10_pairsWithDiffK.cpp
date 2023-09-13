#include <iostream>
using namespace std;

#include <unordered_map>;

int getPairsWithDifferenceK(int *arr, int n, int k) {
	unordered_map<int , int> myMap;
	for (int i=0 ; i<n ; i++){
		myMap[arr[i]]++;
	}
	// cout<<myMap[2]<<endl;
	unordered_map<int , int> :: iterator it;
	it = myMap.begin();
	//cout<<myMap.end()->first<<endl;

	// while (it!=myMap.end()){
    //     cout<<"key : "<<it->first<<" value : "<<it->second<<endl;
    //     it++;
    // }
	int pairs = 0;

	while (it!=myMap.end()){
		//cout<<pairs<<endl;
		int element = it->first;
		//cout<<element<<endl;
		int pairElement1 = element+k;
		int pairElement2 = element-k;
		//cout<<myMap.count(pairElement2)<<endl;
		if (pairElement1==pairElement2){
			int n = myMap[element];
			pairs += n*(n-1)/2;
			myMap[element]=0;
		}
		if (myMap.count(pairElement1)>0){
			pairs += myMap[element]*myMap[pairElement1];
		}
		if (myMap.count(pairElement2)>0){
		 	pairs += myMap[element]*myMap[pairElement2];
		}
		myMap[element]=0;
		it++;
	}
	return pairs;
}

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}