#include <iostream>
#include <queue>
#include <vector>

template <typename T>
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	if (root == NULL){
		return;
	}
	elementsInRangeK1K2(root->left,  k1,  k2);
	if (root->data>=k1 && root->data<=k2){
		cout<<root->data<<" ";
	}
	elementsInRangeK1K2(root->right,  k1,  k2);
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

vector<int> * getRootToNodePath(BinaryTreeNode<int> * root , int data){
    if (root == NULL){
        return NULL;
    }
    if (root->data==data){
        vector<int> * output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int> * leftOutput = getRootToNodePath(root->left,data);
    if (leftOutput!=NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int> * rightOutput = getRootToNodePath(root->right,data);
    if (rightOutput!=NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else{
        return NULL;
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    vector<int> * output = getRootToNodePath(root , 8);
    for (int i=0 ; i<output->size() ; i++){
        cout<<output->at(i)<<endl;
    }
    delete output;
}