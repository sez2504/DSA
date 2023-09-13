//bubble sort iterative
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

Node * swapNodes (Node * head , int i , int j){
    if (i==j){
        return head;
    }
    Node * currentNode = head , * prev = NULL;
    Node * p1 = NULL , * c1 = NULL , * c2= NULL , * p2 =  NULL;
    int pos = 0;
    while (currentNode!=NULL){
        if (pos == i){
            p1=prev;
            c1=currentNode;
        }
        else if (pos==j)
        {
            p2=prev;
            c2=currentNode;
        }
        prev=currentNode;
        currentNode=currentNode->next;
        pos++;
    }
    if (p1!=NULL){
        p1->next=c2;
    }
    else{
        head=c2;
    }
    if (p2!=NULL){
        p2->next=c1;
    }
    else{
        head=c1;
    }
    Node * currentFirstNode = c2->next;
    c2->next=c1->next;
    c1->next=currentFirstNode;

    return head;
}

int length(Node *head)
{
	if (head==NULL){
		return 0;
	}
    int count = 1;
	Node * temp = head;
	while (temp->next!=NULL){
		count++;
		temp=temp->next;
	}
	return count;
}

Node * NodeK (Node * head , int k){
	Node * temp = head;
	for (int i=1 ; i<k ; i++){
		temp=temp->next;
		if (temp==NULL){
			return NULL;
		}
	}
	return temp;
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

Node *bubbleSort(Node *head)
{
	Node * temp = head;
	int n = length(head);
	for (int i= 0 ; i<n-1 ; i++){
		for (int j=0 ; j<n-i-1 ; j++){
            if (NodeK(head,j+1)->data>NodeK(head,j+2)->data){
                cout<<j<<" "<<NodeK(head,j+1)->data<<endl;
                if (NodeK(head,j+1)==head){
                    Node * temp=head->next;
                    swapNodes(head, j,  j+1);
                    head=temp;
                    continue;
                }
                swapNodes(head, j,  j+1);
                print(head);
            }
		}
	}
    return head;
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

int main()
{
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}