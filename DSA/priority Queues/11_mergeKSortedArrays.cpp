#include <iostream>
#include <vector>
using namespace std;

#include <queue>

#include <queue>

vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    priority_queue <int , vector<int> , greater<int> > minHeap;
    
    for (int i=0 ; i<input.size() ; i++){
        //cout<<input[i]->size()<<endl;
        for (int j=0 ; j<input[i]->size() ; j++){
            minHeap.push(input[i]->at(j));
        }
    }

    vector<int> output;

    int size = minHeap.size();

    //cout<<size<<endl;

    for (int i=0 ; i<size ; i++){
        output.push_back(minHeap.top());
        minHeap.pop();
    }

    return output;
}

int main() {
    int k;
    cin >> k;

    vector<vector<int> *> input;

    for (int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}