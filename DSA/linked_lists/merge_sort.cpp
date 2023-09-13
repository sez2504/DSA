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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    int len1 = length(head1);
	int len2 = length(head2);
	int len = max(len1,len2);
	if (len==len2){
		Node * temp;
		temp=head1;
		head1=head2;
		head2=temp;
	}
	if (head1==NULL && head2==NULL){
		return head1;
	}
	else if (head1==NULL){
		return head2;
	}
	else if (head2==NULL){
		return head1;
	}
    Node * tail = head1;
	Node * newhead2 = head2;
	while (tail->next != NULL){

        // print(head1);
		if (head2==NULL){
			break;
		}

		if (head2->data<head1->data){
			newhead2=newhead2->next;
            head2->next=tail;
            tail=head2;
			head2=newhead2;
			head1=tail;
			continue;
        }

		else if (tail->next->data>=head2->data ){
			// cout<<"newhead 2 : "<<newhead2->data<<endl;
            newhead2=newhead2->next;
			head2->next=tail->next;
			tail->next=head2;
			head2=newhead2;
            // cout<<"newhead 2 : "<<newhead2->data<<endl;
		}
        // else if(tail->next->data>=head2->data){
        //     head2->next=tail->next;
		// 	tail->next=head2;
        //     tail=tail->next;
        // }
		tail=tail->next;
	}
	// cout<<"head2 : "<<head2->data<<endl;
	while (head2 !=NULL){
		newhead2=newhead2->next;
		tail->next=head2;
		head2=newhead2;
	}

    return head1;
}

Node *mergeSort(Node *head)
{
	if (head==NULL || head->next==NULL){
		return head;
	}
    Node * newhead1 = head;
	Node * slow = midPoint(head);
	Node * newhead2 = slow->next;
	slow->next=NULL;
	newhead1 = mergeSort(newhead1);
	newhead2 = mergeSort(newhead2);
    cout<<"1 : ";
    print(newhead1); 
    cout<<"2 : ";
    print(newhead2);
    cout<<newhead1->data<<endl;
	Node * smallhead = mergeTwoSortedLinkedLists(newhead1 , newhead2);
	return smallhead;
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
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}