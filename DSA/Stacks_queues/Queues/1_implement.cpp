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
    queueUsingArray(int s){
        data = new T[s];
        firstIndex=-1;
        nextIndex=0;
        size=0;
        capacity=s;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size==0;
    }

    void enque(T element){
        if (size==capacity){
            cout<<"queue is full!"<<endl;
            return;
        }
        data[nextIndex]=element;
        nextIndex=(nextIndex+1)%capacity;
        if (firstIndex==-1){
            firstIndex++;
        }
        size++;
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
    queueUsingArray<int> q(5);
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
    return 0;
}