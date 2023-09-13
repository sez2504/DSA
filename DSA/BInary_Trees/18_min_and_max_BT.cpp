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

#include <climits>

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	pair<int,int> leftAns;
	pair<int,int> rightAns;
	if (root==NULL){
		leftAns.first=INT_MAX;
		leftAns.second=INT_MIN;
		return leftAns;
	}
	leftAns=getMinAndMax(root->left);
	rightAns=getMinAndMax(root->right);
	pair<int,int> ans;
	ans.first=min(min(leftAns.first,rightAns.first),root->data);
	ans.second=max(max(leftAns.second,rightAns.second),root->data);
	return ans;
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
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    pair<int, int> ans = getMinAndMax(root);
    cout << ans.first << " " << ans.second;
}