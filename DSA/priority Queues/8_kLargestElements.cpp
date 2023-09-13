#include <iostream>
#include <vector>
using namespace std;

vector<int> kLargest(int arr[], int n, int k) {
    vector<int> v;
    if (n==0){
        return v;
    }
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

    
    return v;

}

int main() {
	
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
    
    int k;
    cin >> k;
    
    vector<int> output = kLargest(input, size, k);
    for(int i = 0; i < output.size(); i++)
        cout << output[i] << endl;
	
	return 0;
}