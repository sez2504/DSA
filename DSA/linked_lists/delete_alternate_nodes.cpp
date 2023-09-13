//delete alternate Node in a linked list
#include <iostream>

class Node {
public:
    int data;
    Node * next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    
    ~Node() {
        if(next) {
            delete next;
        }
    }
};

using namespace std;

Node *deleteNode(Node *head, int pos)
{
	if (pos==0){
		head=head->next;
		return head;
	}
    Node *temp ;
    temp = head;
    for (int i=0 ; i<pos-1 ; i++){
        temp=temp->next;
		if (temp->next==NULL){
			return head; //pos exceeds last index , no change
		}
    }
    temp->next=temp->next->next;
    return head;
}

void deleteAlternateNodes(Node *head) {
    if (head==NULL || head->next==NULL){
        return ;
    }
    Node * temp = head->next;
    int i=1;
    while (temp!=NULL && temp->next!=NULL && temp->next->next!=NULL) {
        deleteNode(head,i);
        temp=temp->next->next;
        i+=1;
    }
    cout<<temp->data<<endl;
    cout<<i<<endl;
    deleteNode(head,i);
}

/*alt:-
void deleteAlternateNodes(Node *head) {
    if (head==NULL || head->next==NULL){
        return ;
    }
    deleteAlternateNodes(head->next->next);
    head->next=head->next->next;
}
*/

Node* takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL) {
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
    cout << endl;
}

int main() {
    Node *head = takeinput();
    deleteAlternateNodes(head);
    print(head);
    delete head;
    return 0;
}