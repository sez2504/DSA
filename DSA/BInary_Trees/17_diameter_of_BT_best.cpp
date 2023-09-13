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

class Pair{
    public:
    int height;
    int diameter;
    Pair(){
        height=0;
        diameter=0;
    }
};

using namespace std;

int height(BinaryTreeNode<int>* root) {
    if (root==NULL){
		return 0;
	}
	if (root->left == NULL && root->right == NULL){
		return 1;
	}
	return 1+max(height(root->left),height(root->right));
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

Pair helper(BinaryTreeNode<int> * root){
    Pair p;
    if (root==NULL){
        return p;
    }
    Pair leftAns = helper(root->left);
    Pair rightAns = helper(root->right);
    int leftHeight = leftAns.height;
    int leftDiameter = leftAns.diameter;
    int rightHeight = rightAns.height;
    int rightDiameter = rightAns.diameter;

    int height = 1 + max(leftHeight,rightHeight);
    int diameter = max(leftHeight+rightHeight , max(leftDiameter,rightDiameter));

    p.diameter=diameter;
    p.height=height;
    
    return p;
}

int diameter (BinaryTreeNode<int> * root){
    Pair p = helper(root);
    return p.diameter;
}

BinaryTreeNode<int> * takeInputLevelWise(){
    int rootData;
    cout<<"Enter Data"<<endl;
    cin>>rootData;
    if (rootData==-1){
        int ch;
        cout<<"Press 1 to enter NULL here and 0 to enter -1"<<endl;
        cin>>ch;
        if (ch==1){
            return NULL;
        }
    }

    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);
    
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter left child of "<<front->data<<endl;
        
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData==-1){
            int ch;
            cout<<"Press 1 to enter NULL here and 0 to enter -1"<<endl;
            cin>>ch;
            if (ch==1){
                BinaryTreeNode<int> * child = NULL;
                front->left=child;
            }
            else{
                BinaryTreeNode<int> * child = new BinaryTreeNode<int>(-1);
                front->left=child;
                pendingNodes.push(child);
            }
        }
        else{
            BinaryTreeNode<int> * child = new BinaryTreeNode<int>(leftChildData);
            front->left=child;
            pendingNodes.push(child);
        }
        
        cout<<"Enter right child of "<<front->data<<endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData==-1){
            int ch;
            cout<<"Press 1 to enter NULL here and 0 to enter -1"<<endl;
            cin>>ch;
            if (ch==1){
                BinaryTreeNode<int> * child = NULL;
                front->right=child;
            }
            else{
                BinaryTreeNode<int> * child = new BinaryTreeNode<int>(-1);
                front->right=child;
                pendingNodes.push(child);
            }
        }
        else{
            BinaryTreeNode<int> * child = new BinaryTreeNode<int>(rightChildData);
            front->right=child;
            pendingNodes.push(child);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout << diameter(root) <<endl;
}