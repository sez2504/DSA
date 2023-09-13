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

/*Node *swapNodes(Node *head, int i, int j)
{
	Node * temp = head;
	int k=0;
	Node * node1prev=head;
	while (k<i-1){
		node1prev = node1prev->next;
        k++;
	}
    Node * node1=node1prev->next;
	Node * node2prev = head;
    k=0;
	while (k<j-1){
		node2prev = node2prev->next;
        k++;
	}
    Node * node2=node2prev->next;
    temp=node2->next; //we cant do temp = node 2 , changes in node 2 will reflect on temp and become infinite loop
    if ((i==0 || j==0)&&(i-j!=1&&i-j!=-1)){
        if (i==0){
            node1=head;
            node2->next=node1->next;
            node2prev->next=node1;
            node1->next=temp;
            return node2;
        }
        else{
            temp=node1->next;
            node2=head;
            node1->next=node2->next;
            node1prev->next=node2;
            node2->next=temp;
            return node1;
        }
    }
    else if ((i==0 || j==0)&&(i-j==1||i-j==-1)){
        if (i==0){
            node1=head;
            node2->next=node1;
            node1->next=temp;
            return node2;
        }
        else{
            temp=node1->next;
            node2=head;
            node1->next=node2;
            node2->next=temp;
            return node1;
        }
    }
    else if (i-j==1 || j-i == 1){
        if (i>j){
            temp=node1->next;
            node2prev->next=node1;
            node1->next=node2;
            node2->next=temp;
            return head;
        }
        node1prev->next=node2;
        node2->next=node1;
        node1->next=temp;
        return head;
    }
    node1prev->next=node2;
    node2->next=node1->next;
    node2prev->next=node1;
    node1->next=temp;
	return head;
}*/

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
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}