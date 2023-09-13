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

class Pair{
	public:
	Node * tail;
	Node * head;
};

Pair reverseLinkedListRec2(Node * head){
	 if (head==NULL || head->next==NULL){
		Pair ans;
		ans.head=head;
		ans.tail=head;
		return ans;
	}
	Pair smallhead = reverseLinkedListRec2(head->next);
	smallhead.tail->next=head;
	head->next=NULL;
	Pair ans;
	ans.head=smallhead.head;
	ans.tail=head;
	return ans;
}

Node *reverseLinkedListRec(Node *head)
{
    return reverseLinkedListRec2(head).head;
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

	while(t--)
	{
		Node *head = takeinput();
		head = reverseLinkedListRec(head);
		print(head);
	}

	return 0;
}