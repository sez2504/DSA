#include<iostream>
using namespace std; 

class Deque {
    int *data;
    int lastindex;
    int firstindex;
    int capacity;

    public:
    Deque(int capacity){
        data = new int[capacity];
        lastindex=-1;
        firstindex=-1;
        this->capacity=capacity;
    }

    void print (){
        for (int i=0 ; i<lastindex  ; i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }

    void insertFront(int element){
        if (firstindex ==-1 && lastindex==-1){
            firstindex=0;
            lastindex=0;
            data[firstindex]=element;
            return;
        }
        if ((firstindex+1)%capacity==lastindex){
            cout<<-1<<endl;
            return;
        }
        firstindex=(firstindex+1)%capacity;
        data[firstindex]=element;
        // for (int i=firstindex ; i<lastindex  ; i++){
        //     cout<<data[i]<<" ";
        // }
        // cout<<endl;
    }

    void insertRear(int element){
        if (firstindex ==-1 && lastindex==-1){
            firstindex=0;
            lastindex=0;
            data[firstindex]=element;
            return;
        }
        if (firstindex==lastindex-1 || lastindex==0 && firstindex==capacity-1){
            cout<<-1<<endl;
            return;
        }
        if (lastindex==0){
            lastindex=capacity-1;
        }
        else{
            lastindex--;
        }
        data[lastindex]=element;
        // for (int i=firstindex ; i<lastindex  ; i++){
        //     cout<<data[i]<<" ";
        // }
        // cout<<endl;
    }

    void deleteFront (){
        if (firstindex==-1 && lastindex==-1){
            cout<<-1<<endl;
            return;
        }
        if (firstindex==lastindex){
            firstindex=-1;
            lastindex=-1;
            return;
        }
        if (firstindex==0){
            firstindex=capacity-1;
        }
        else{
            firstindex--;
        }
        // for (int i=firstindex ; i<lastindex  ; i++){
        //     cout<<data[i]<<" ";
        // }
        // cout<<endl;
    }

    void deleteRear() {
        if (firstindex==-1 && lastindex==-1){
            cout<<-1<<endl;
            return;
        }
        if (firstindex==lastindex){
            firstindex=-1;
            lastindex=-1;
            return;
        }
        lastindex=(lastindex+1)%capacity;
    }

    int getFront(){
        if ((firstindex==-1) && (lastindex==-1)){
            return -1;
        }
        else{
            return data[firstindex];
        }
    }

    int getRear(){
        // for (int i=firstindex ; i<lastindex  ; i++){
        //     cout<<data[i]<<" ";
        // }
        // cout<<endl;
        if ((firstindex==-1) && (lastindex==-1)){
            return -1;
        }
        else{
            return data[lastindex];
        }
    }
};

// Driver program to test above function
int main()
{
    Deque dq(10);
    int choice,input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            // case 4:
            //     dq.deleteRear();
            //     break;
            // case 5:
            //     cout << dq.getFront() << "\n";
            //     break;
            // case 6:
            //     cout << dq.getRear() << "\n";
            //     break;
            default:
                return 0;
        }
    }
    
    return 0;
}