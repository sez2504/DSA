#include <iostream>
#include <queue>

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

class Pair{
	public:
	Node<int> * head;
	Node<int> * tail;

	Pair(){
		this->head=NULL;
		this->tail=NULL;
	}
};

Pair constructLinkedList_helper(BinaryTreeNode<int>* root) {
	if (root==NULL){
		Pair p;
		return p;
	}
	Node<int> * rootdata = new Node<int>(root->data);
	Pair p;
	Pair leftTree = constructLinkedList_helper(root->left);
	Pair rightTree = constructLinkedList_helper(root->right);
    if (root->left!=NULL){
        //constructLinkedList_helper(root->left).tail->next=rootdata;
		p.head = leftTree.head;
		leftTree.tail->next=rootdata;
		//cout<<" tail : "<<p.tail->data<<endl;
    }
	else{
		p.head=rootdata;
	}
    if (root->right!=NULL){
        rootdata->next=rightTree.head;
		p.tail = rightTree.tail;
    }
	else{
		p.tail=rootdata;
	}	
	return p; 
}

Node<int> * constructLinkedList(BinaryTreeNode<int>* root) {
	return constructLinkedList_helper(root).head;
}

BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}