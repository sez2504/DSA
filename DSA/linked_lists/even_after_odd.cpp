#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;

Node *evenAfterOdd(Node *head)
{
	if (head==NULL || head->next==NULL){
		return head;
	}
	Node * temp = head;
	Node * oddHead = NULL ;
	Node * oddTail = NULL;
	Node * evenHead = NULL ;
	Node * evenTail = NULL;
	while (temp!=NULL){
		if (temp->data%2!=0){
			if (oddHead==NULL){
				oddHead=temp;
				oddTail=temp;
                //cout<<oddHead->data<<endl;
			}
			else{
				oddTail->next=temp;
				oddTail=temp;
			}
			///cout<<oddTail->data<<endl;
		}
		else {
			if (evenHead==NULL){
				evenHead=temp;
				evenTail=temp;
			}
			else{
				evenTail->next=temp;
				evenTail=temp;
			}
			//cout<<evenTail->data<<endl;
		}
        //cout<<temp->data<<endl;
		temp=temp->next;
	}
    if (oddHead==NULL || evenHead==NULL){
        return head;
    }
	oddTail->next=evenHead;
    evenTail->next=NULL;
	return oddHead;
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}