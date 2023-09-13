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

Node * insertNode(Node *head, int pos , int element)
{
    if (pos==0){
        Node * n = new Node(element);
        n->next=head;
        head = n;
        return head;
    }
    if (head==NULL && pos==0){
        Node * n = new Node(element);
        head=n;
        return head;
    }
    if (head==NULL && pos!=0){
        return head;
    }
    // if (head->next==NULL && pos>0){
    //     return head;
    // }
    Node * smallNode = insertNode(head->next , pos-1 , element );
    if (pos==1){
        Node * n = new Node(element);
        n->next=head->next;
        head->next=n;
    }
    // else if (pos==0){
    //     Node * n = new Node(element);
    //     head->next=n;
    //     return head;
    // }
    return head;
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
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
	
        int element;
        cin>>element;
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = insertNode(head, pos , element);
		print(head);
	

	return 0;
}