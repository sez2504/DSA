#include <iostream>
#include <queue>
#include <vector>

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
	
	vector<Node<int>*> v;
	if (root==NULL){
		v.push_back(NULL);
		return v;
	}
	
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	pendingNodes.push(NULL);

	Node<int> * head = NULL;
	Node<int> * tail = head;

	while (!pendingNodes.empty()){
		BinaryTreeNode<int> * front = pendingNodes.front();
		pendingNodes.pop();

		if (front!=NULL){
			if (head==NULL){
				head=new Node<int>(front->data);
				tail=head;
			}
			else{
				tail->next=new Node<int>(front->data);
				tail=tail->next;
			}
            if (pendingNodes.empty()){
                pendingNodes.push(NULL);
            }
		}

		else{
			v.push_back(head);
			if (pendingNodes.empty()){
				return v;
			}
			head=NULL;
			tail=NULL;
			pendingNodes.push(NULL);
			continue;
		}
		
		if (front->left!=NULL){
			pendingNodes.push(front->left);
		}
		if (front->right!=NULL){
			pendingNodes.push(front->right);
		}
	}
	return v;
}

BinaryTreeNode<int> *takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}