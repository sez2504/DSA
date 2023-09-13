#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue{
    vector<int> pq;
    //int nextindex;

    public:
    PriorityQueue(){
        //nextindex=0;
    }

    bool isEmpty(){
        return pq.size()==0;
    }

    int getSize(){
        return pq.size();
    }

    int getMin(){
        if (isEmpty()){
            cout<<"underflow"<<endl;
            return -1;
        }
        return pq[0];
    }

    void insert (int item){
        pq.push_back(item);
        int i = pq.size()-1; //i is childindex
        //nextindex++;
        if (i==0){
            return;
        }
        if (pq[(i-1)/2]<item){
            return;
        }
        else{
            while (pq[(i-1)/2]>item || i>0){
                int j = (i-1)/2; //j is parentIndex
                int temp = pq[j];
                pq[j]=pq[i];
                pq[i]=temp;
                i=j;
            }
        }
    }

    int removeMin(){
        if (isEmpty()){
            cout<<"underFlow"<<endl;
            return -1;
        }
        int ans = pq[0];
        int temp = pq[0];
        pq[0]=pq[pq.size()-1];
        pq[pq.size()-1]=pq[0];
        int parentIndex=0;
        int child1=1;
        int child2=2;
        while ((pq[parentIndex]>pq[child1] || pq[parentIndex]>pq[child2]) && child1<=pq.size()-1){
            if (child2>pq.size()-1){
                pq.pop_back();
                return ans;
            }
            if (pq[child1]>pq[child2]){
                if (pq[parentIndex]>pq[child2]){
                    int temp = pq[parentIndex];
                    pq[parentIndex]=pq[child2];
                    pq[child2]=temp;
                    parentIndex=child2;
                    child1=parentIndex*2+1;
                    child2=parentIndex*2+2;
                }
            }
            else{
                if (pq[parentIndex]>pq[child1]){
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

    void print(){
        for (int i=0 ; i<pq.size() ; i++){
            cout<<pq[i]<<" ";
        }
        cout<<endl;
    }

};

int main()
{
    PriorityQueue q;
    cout<<q.isEmpty()<<endl;
    q.insert(3);
    q.insert(2);
    cout<<q.removeMin()<<endl;
    q.insert(1);
    q.insert(-2);
    q.insert(-9);
    cout<<q.removeMin()<<endl;
    q.insert(9);
    q.insert(19);
    cout<<q.removeMin()<<endl;
    q.print();
    return 0;
}