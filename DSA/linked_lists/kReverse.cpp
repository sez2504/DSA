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

Node * reverseLinkedListRec(Node *head) {
	Node * curr= head;
	Node * prev=NULL;
	Node * nextadd=NULL;
   while (curr!=NULL){
	   nextadd=curr->next;
	   curr->next=prev;
	   prev=curr;
	   curr=nextadd;
	   //nextadd=nextadd->next;
   }
   return prev;
}

Node * NodeK (Node * head , int k){
	Node * temp = head;
	for (int i=1 ; i<k-1 ; i++){
		temp=temp->next;
		if (temp==NULL){
			return NULL;
		}
	}
	return temp;
}

Node * kReverse(Node *head, int k)
{
	if (head==NULL || (NodeK(head,k)==NULL) || NodeK(head,  k)->next==NULL || NodeK(head,  k)->next->next==NULL ){
		head = reverseLinkedListRec(head);
		return head;
	}
	if (k==1 || k==0){
		return head;
	}
    Node * headnext = head->next;
	Node * tailOneprev = NodeK(head, k);
    Node * tailOne = tailOneprev->next;
	Node * newhead = tailOne->next;
    newhead = kReverse(newhead , k);
	tailOne->next=NULL;
	head=reverseLinkedListRec(head);
    cout<<"head: " ; 
    print(head);
    //headnext becomes second last and tailprev becomes second after reversal
    cout<<"tailone : "<<headnext->data<<endl;
    headnext=headnext->next;
    tailOneprev=tailOneprev->next;
    cout<<tailOneprev->data<<endl;
	headnext->next=newhead;
    cout<<head->data<<endl;
    cout<<"newhead: " ; 
    print(newhead);
	return head;
}

/*alt:-
Node * kReverse(Node *head, int k)
{
    if (k==0 || k==1){
        return head;
    }
    Node * current = head;
    Node * prev = null;
    Node * fwd = null;
    int count = 0;
    //reverse first k nodes
    while(count<k && current!=null){
        fwd=current->next;
        current -> next = prev;
        prev = current;
        current = fwd;
        count++;
    }
    if (fwd!=null){
        head->next = kreverse (fwd,k);
    }
    return prev;
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
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}
	
	return 0;
}