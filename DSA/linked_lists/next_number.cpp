#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;

Node *reverseLinkedList(Node *head) {
	Node * curr= head;
	Node * prev=NULL;
	Node * nextadd=NULL;
   while (curr!=NULL){
	   nextadd=curr->next;
	   curr->next=prev;
	   prev=curr;
	   curr=nextadd;
	   //nextadd=nextadd->next;
   }
   return prev;
}

Node * NextLargeNumber(Node * head){
    head = reverseLinkedList(head);
    int carry = 1 , num ;
    Node * ptr = head , *prev = NULL;
    while (ptr)
    {
        num = ((ptr->data)+carry)%10;
        carry = ((ptr->data)+carry)/10;
        ptr->data=num;
        prev=ptr;
        ptr = ptr->next;
    }
    if (carry){
        Node * tail = new Node(carry);
        prev->next = tail;
    }
    return reverseLinkedList(head);
}

// Node* NextLargeNumber(Node *head) {
//     static int flag = -1;
//     if (head==NULL){
//         return head;
//     }
//     if (head->next==NULL){
//         if (head->data<0){
//             head->data*=-1;
//         }
//         if (head->data==9){
//             Node * newhead = new Node(1);
//             head->data=0;
//             newhead->next=head;
//             head=newhead;
//         }
//         else{
//             head->data=head->data+1;
//         }
//         return head;
//     }
//     Node * smallhead = NextLargeNumber(head->next);
//     if (head->next->data==0 && flag==-1){
//         head->data=head->data+1;
//     }
//     else{
//         flag=0;
//     }
//     return head;
// }

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    
    head = NextLargeNumber(head);
    print(head);
    return 0;
}
