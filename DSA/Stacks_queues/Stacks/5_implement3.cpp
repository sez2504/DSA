#include <iostream>
#include <climits>
using namespace std;

template <typename T>

class StackUsingArray {
    T * data;
    int nextIndex;
    int capacity;

    public:
    StackUsingArray (){
        data = new T[5];
        nextIndex=0;
        capacity=5;
    }

    int size(){
        return nextIndex;
    }

    bool isEmpty(){
        // if (nextIndex==0){
        //     return true;
        // }
        // else{
        //     return false;
        // }

        return nextIndex==0;
    }

    void push(int element){
        if (nextIndex==capacity){
            T * newData = new T [2*capacity];
            for (int i=0 ; i<capacity ; i++){
                newData[i]=data[i];
            }
            capacity*=2;
            data=newData;
            delete [] newData;
        }
        data[nextIndex]=element;
        nextIndex++;
    }

    T pop(){
        if (nextIndex==0){
            cout<<"stack empty"<<endl;
            return 0;
        }
        return data[--nextIndex];
    }

    T top(){
        if (nextIndex==0){
            cout<<"stack empty"<<endl;
            return 0;
        }
        return data[nextIndex-1];
    }
};

int main()
{
    StackUsingArray<char> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}