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
    //stastically
    Node * head;
    Node n1(1);
    head=&n1;
    Node n2(2);
    n1.next=&n2;
    cout<<n1.data<<" "<<n2.data<<endl;
    cout<<head->data<<" "<<n1.next->data<<" "<<head->next->data<<endl;  

    //dynamically
    Node * n3 = new Node(10);
    n2.next=n3;
    Node * head2 = n3;
    Node * n4 = new Node(20);
    n3->next=n4;
    print(head);
    print(head2);
    return 0;
}