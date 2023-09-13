#include <iostream>
#include <queue>

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

void printLevelWise(BinaryTreeNode<int> *root) {
	if (root==NULL){
		return;
	}
	//cout<<root->data<<":";
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	pendingNodes.push(NULL);
	while (!pendingNodes.empty()){
		BinaryTreeNode<int> * front = pendingNodes.front();
		pendingNodes.pop();
		if (front==NULL){
			cout<<endl;
			if (!pendingNodes.empty()){
				pendingNodes.push(NULL);
			}
		}
		else{
			cout<<front->data<<" ";
			if (front->left!=NULL){
				pendingNodes.push(front->left);
			}
			if (front->right!=NULL){
				pendingNodes.push(front->right);
			}
		}
	}
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
    printLevelWise(root);
}