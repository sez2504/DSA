/*You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' 
Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. 
Continue the same until the end of the linked list.
To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.*/

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

Node *skipMdeleteN(Node *head, int M, int N)
{
    if (head==NULL){
        return head;
    }
	Node * newLLHead = NULL;
	Node * newLLTail = NULL;
	Node * temp = head;
	if (M==0){
		return NULL;
	}
	else if (N==0){
		return head;
	}
	int i = 1 ; 
	bool isM = true;
    //cout<<temp->next->data<<endl;
	while (temp!=NULL){
        //cout<<temp->next->data<<endl;
        if (newLLTail==NULL && isM){
            newLLTail=temp;
            newLLHead=newLLTail;
        }
		else if (i%M==0 && isM){
            //cout<<"IN"<<endl;
			newLLTail->next=temp;
			newLLTail=temp;
			isM=false;
			i=0;
		}
		else if (isM){
			newLLTail->next=temp;
			newLLTail=temp;
		}
		else if (i%N==0 ){
			isM=true;
			i=0;
		}
		i++;
        temp=temp->next;
        newLLTail->next=NULL;
        //cout<<temp->next->data<<endl;
	}
	return newLLHead;
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
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}