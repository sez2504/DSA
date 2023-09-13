#include <iostream>
using namespace std;

template <typename T>

class queueUsingArray{
    T * data;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;
    
    public:
    queueUsingArray(){
        data = new T[5];
        firstIndex=-1;
        nextIndex=0;
        size=0;
        capacity=5;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size==0;
    }

    void enque(T element){
        if (size==capacity){
            T  * newData = new T[2*capacity];
            int j=0;
            //cout<<"firstindex: "<<firstIndex<<" "<<data[firstIndex]<<endl;
            for (int i=firstIndex ; i<capacity ; i++){
                //cout<<data[i]<<" ";
                newData[j]=data[i];
                j++;
            }
            //cout<<"NEWDATA"<<endl;
            // for (int i=0 ; i<2*capacity ; i++){
            //     cout<<newData[i]<<" ";
            // }
            // cout<<endl;
            for (int i = 0; i < firstIndex; i++)
            {
                cout<<data[i]<<" ";
                newData[j]=data[i];
                j++;
            }
            data=newData;
            delete [] newData;
            firstIndex=0;
            nextIndex=capacity;
            capacity*=2;
        }
        //cout<<"nextindex : "<<nextIndex<<endl;
        data[nextIndex]=element;
        nextIndex=(nextIndex+1)%capacity;
        if (firstIndex==-1){
            firstIndex++;
        }
        size++;
        // cout<<"DATA"<<endl;
        //     for (int i=0 ; i<capacity ; i++){
        //         cout<<data[i]<<" ";
        //     }
        //     cout<<endl;
    }

    void print(){
        for (int i=firstIndex ; i<nextIndex ; i++){
            cout<<data[i]<<" ";
        }
    }

    T front(){
        if (firstIndex==-1){
            return 0;
        }
        return data[firstIndex];
    }

    T deque(){
        if (isEmpty()){
            cout<<"queue is empty!"<<endl;
            return 0;
        }
        //cout<<"firstindex: "<<firstIndex<<endl;
        T ans = data[firstIndex];
        firstIndex=(firstIndex+1)%capacity;
        size--;
        if (size==0){
            firstIndex=-1;
            nextIndex=0;
        }
        return ans;
    }
};

int main()
{
    queueUsingArray<int> q;
    q.enque(10);
    q.enque(20);
    q.enque(30);
    q.enque(40);
    q.enque(50);
    q.enque(60);

    cout<<q.front()<<endl;
    cout<<q.deque()<<endl;
    cout<<q.deque()<<endl;
    cout<<q.deque()<<endl;
    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;

    cout<<endl;
    q.print();
    cout<<endl;
    return 0;
}