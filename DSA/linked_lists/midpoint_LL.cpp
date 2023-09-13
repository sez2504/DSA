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

Node *midPoint(Node *head)
{
	if (head==NULL){
		return head;
	}
    Node * slow = head;
	Node * fast = slow->next;
	while(fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}

/*alt:-
int length(Node * head){
	if (head==NULL){
		return 0;
	}
	int len=0;
	Node * temp = head;
	while (temp->next!=NULL){
		len++;
	}
	return len;
}

Node *midPoint(Node *head)
{
    Node * mid = head;
	int len = length(head);
	int midpt = (len-1)/2;
	for (int i = 0 ; i<midpt ; i++ ){
		mid=mid->next;
	}
	return mid;
}
*/

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

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		Node *mid = midPoint(head);
		if (mid != NULL)
		{
			cout << mid->data;
		}
		cout << endl;
	}
	return 0;
}