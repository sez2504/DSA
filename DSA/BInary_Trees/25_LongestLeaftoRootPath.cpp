#include <iostream>
#include <vector>
#include <queue>

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

#include <vector>
#include <algorithm>

vector<int>* longestPath_helper(BinaryTreeNode<int>* root , vector<int>* v) {
    if (root==NULL){
        return v;
    }
    if (root->left==NULL && root->right==NULL){
        cout<<"IN"<<endl;
        v->push_back(root->data);
        return v;
    }
    vector<int> * r ; 
    vector<int> * l;
    r=longestPath_helper(root->right , v);
    l=longestPath_helper(root->left , v);
    cout<<r->size()<<endl;
    if (r->size()>l->size()){
        v=r;
        return v;
    }
    else{
        v=l;
        return v;
    }
    v->push_back(root->data);
}

vector<int>* longestPath(BinaryTreeNode<int>* root) {
    vector<int> * v = new vector<int>;
    return longestPath_helper(root,v);
    //return longestPath_helper(root, v);
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

int main() {
    BinaryTreeNode<int>* root = takeInput();
    vector<int> *output = longestPath(root);
    vector<int> :: iterator i = output -> begin();
    while(i != output -> end()) {
    	cout << *i << endl;
    	i++;
    }
}
