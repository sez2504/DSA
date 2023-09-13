#include <iostream>
using namespace std;

#include <vector>

class PriorityQueue {
    vector<int> pq;

   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        pq.push_back(element);
        int childIndex = pq.size()-1;
        int parentIndex = (childIndex-1)/2;
        while (childIndex>0 && pq[parentIndex]<pq[childIndex]){
            int temp = pq[parentIndex];
            pq[parentIndex]=pq[childIndex];
            pq[childIndex]=temp;
            childIndex=parentIndex;
            parentIndex=(childIndex-1)/2;
        }
    }

    int getMax() {
        if (isEmpty()){
            cout<<"underFlow"<<endl;
            return -1;
        }
        return pq[0];
    }

    int removeMax() {
        if (isEmpty()){
            cout<<"underFlow"<<endl;
            return -1;
        }
        int ans = pq[0];
        int temp = pq[pq.size()-1];
        pq[pq.size()-1]=pq[0];
        pq[0]=temp;
        int parentIndex=0;
        int child1=1;
        int child2=2;
        while ((pq[parentIndex]<pq[child1]||pq[parentIndex]<pq[child2])&&child1<pq.size()){
            if (child2>=pq.size()-1){
                pq.pop_back();
                return ans;
            }
            if (pq[child1]<pq[child2]){
                if (pq[parentIndex]<pq[child2]){
                    int temp = pq[parentIndex];
                    pq[parentIndex]=pq[child2];
                    pq[child2]=temp;
                    parentIndex=child2;
                    child1=parentIndex*2+1;
                    child2=parentIndex*2+2;
                }
            }
            else{
                if (pq[parentIndex]<pq[child1]){
                    int temp = pq[parentIndex];
                    pq[parentIndex]=pq[child1];
                    pq[child1]=temp;
                    parentIndex=child1;
                    child1=parentIndex*2+1;
                    child2=parentIndex*2+2;
                }
            }
        }
        pq.pop_back();
        return ans;
    }

    int getSize() { 
        return pq.size();
    }

    bool isEmpty() {
        return pq.size()==0;
    }
};

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}