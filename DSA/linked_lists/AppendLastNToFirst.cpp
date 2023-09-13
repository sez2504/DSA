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

int length(Node *head) {
	if (head==NULL){
		return 0;
	}
	int smalloutput = length(head->next);
	return smalloutput+1;
}

Node *appendLastNToFirst(Node *head, int n)
{
	int len = length(head);
	if (len==0 || n==0){
		return head;
	}
	else if (n>=len){
		head=NULL;
		return head;
	}
	int breakindex = len-n-1;
	Node * tail = head;
	for (int i=0 ; i<breakindex ; i++){
		tail=tail->next;
	}
	Node * newhead = tail->next;
	Node * newtail = newhead;
	while (newtail->next!=NULL){
		newtail=newtail->next;
	}
	newtail->next=head;
	tail->next=NULL;
	return  newhead;
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
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}