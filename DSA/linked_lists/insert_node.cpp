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
    Node * n = new Node(element);
    if (pos==0){
        n->next=head;
        head = n;
        return head;
    }
    Node *temp ;
    temp = head;
    for (int i=0 ; i<pos-1 ; i++){
        if (temp->next==NULL){
            return head;
        }
        temp=temp->next;
    }
    n->next=temp->next; //we cant do temp next = n first as we will lose the adress of temp next that way
    temp->next=n;
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