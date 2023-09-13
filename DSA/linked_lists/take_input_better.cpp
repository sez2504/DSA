#include <iostream>
using namespace std;

class Node{
    public:
    int data ;
    Node * next;

    Node (int data){
        this->data=data;
        next=NULL;
    }
};


Node * takeInputBetter(){
    int data;
    cin >> data;
    Node * head = NULL;
    Node * tail = NULL;
    while (data != - 1)
    {
        Node * n = new Node(data);
        if (head == NULL){
            head=n;
            tail=n;
        }
        else{
            tail->next=n;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}

void print (Node * head){
    Node * temp = head; //this enbles us to retain head
    while (temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    Node * head = takeInputBetter();
    print (head);
    return 0;
}