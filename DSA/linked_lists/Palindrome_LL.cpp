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
Node * reverse(Node * head){
	Node * curr = head;
	Node * prv = NULL;
	Node * next = NULL;
	while(curr != NULL){
        next = curr->next;
        curr->next = prv;
        prv = curr;
        curr = next;
    }
    return prv;
 
}
void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}
bool isPalindrome(Node *head)
{
	if (head==NULL || head->next==NULL){
		return true;
	}
    int n = length(head);
	Node * tail = head;
	if (n%2==0){
		for (int i= 0 ; i<n/2-1 ; i++){
			tail=tail->next;
		}
	}
	else{
		for (int i= 0 ; i<n/2 ; i++){
			tail=tail->next;
		}
	}
	cout<<tail->data<<endl;
	Node * newhead = tail->next;
	newhead = reverse(newhead);
	print(newhead);
	Node * newtail = newhead;
	while (newtail->next != NULL){
		newtail=newtail->next;
	}
	tail->next=NULL;
	while (newhead!=NULL){
		if (head->data!=newhead->data){
			cout<<head->data<<" "<<newhead->data<<endl;
			return false;
		}
		cout<<head->data<<" "<<newhead->data<<endl;
		head=head->next;
		newhead=newhead->next;
	}
	return true;
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
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}