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


//faulty
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

/*alt:-
Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;
 
     Base cases 
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    Pick either a or b, and recur 
    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
*/

/*alt:-
node* findMid(node *head) {

	if(head == NULL) {

		return head;

	}

	node *slow = head, *fast = head;

	while(fast -> next != NULL && fast -> next -> next != NULL) {

		slow = slow -> next;

		fast = fast -> next -> next;

	}

	return slow;

}



node* merge(node *head1, node *head2) {

	if(head1 == NULL) {

		return head2;

	}

	if(head2 == NULL) {

		return head1;

	}

	node *head = NULL, *tail = NULL;

	if(head1 -> data < head2 -> data) {

		head = head1;

		tail = head1;

		head1 = head1 -> next;

	}

	else {

		head = head2;

		tail = head2;

		head2 = head2 -> next;

	}



	while(head1 != NULL && head2 != NULL) {

		if(head1 -> data < head2 -> data) {

			tail -> next = head1;

			tail = head1;

			head1 = head1 -> next;

		}

		else {

			tail -> next = head2;

			tail = head2;

			head2 = head2 -> next;

		}

	}

	if(head1 != NULL) {

		tail -> next = head1;

	}

	if(head2 != NULL) {

		tail -> next = head2;

	}

	return head;

}*/

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

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}