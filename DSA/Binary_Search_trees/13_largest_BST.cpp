/*Given a Binary tree, find the largest BST subtree. 
That is, you need to find the BST with maximum height in the given binary tree. 
You have to return the height of largest BST.*/

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

#include <climits>

bool isBST_helper(BinaryTreeNode<int> * root , int min = INT_MIN , int max = INT_MAX){
    if (root == NULL){
        return true;
    }
    if (root->data < min || root->data>max){
        return false;
    }
    bool isLeftOk = isBST_helper(root->left , min , root->data-1);
    bool isRightOk = isBST_helper(root->right , root->data+1  , max);
    return isLeftOk && isRightOk;
}

bool isBST(BinaryTreeNode<int> *root) {
	return isBST_helper(root);
}

int height(BinaryTreeNode<int> * root){
	if (root==NULL){
		return 0;
	}
	return 1+max(height(root->left),height(root->right));
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
	if (root==NULL){
		return 0;
	}
	if (isBST(root)){
		return height(root);
	}
	else{
		return max(largestBSTSubtree(root->left),largestBSTSubtree(root->right));
	}
	//return 1+max(largestBSTSubtree(root->left),largestBSTSubtree(root->right));
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
    cout << largestBSTSubtree(root);
    delete root;
}