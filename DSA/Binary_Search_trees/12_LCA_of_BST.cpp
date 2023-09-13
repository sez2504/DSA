/*Given a binary search tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) of the 
given two nodes in the BST.
LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants. */

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
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;

bool findNode (BinaryTreeNode<int> * root ,int val){
	if (root==NULL){
		return false;
	}
	if (root->data==val){
		return true;
	}
	return findNode(root->left,  val) || findNode(root->right,  val);
}

int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
	if (root==NULL){
		return -1;
	}
	if (findNode(root ,  val1) && findNode(root,  val2)){
		if (findNode(root->left ,  val1) && findNode(root->left ,  val2)){
			//cout<<"INLEFT"<<endl;
			return getLCA(root->left,  val1,  val2);
		}
		else if (findNode(root->right ,  val1) && findNode(root->right ,  val2)){
			//cout<<"INRIGHT"<<endl;
			return getLCA(root->right,  val1,  val2);
		}
		return root->data;
	}
    else if (findNode(root ,  val1)){
		return val1;
	}
	else if (findNode(root,  val2)){
		return val2;
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
    int a, b;
    cin >> a >> b;
    cout << getLCA(root, a, b);
    delete root;
}