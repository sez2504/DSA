#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode{
    public:

    T data;
    BinaryTreeNode<T> * left;
    BinaryTreeNode<T> * right;

    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }

    ~BinaryTreeNode(){
        delete left;
        delete right;
    }

};

void printTree(BinaryTreeNode<int> * root){
    if (root==NULL){
        return;
    }
    cout<<root->data<<":";
    if (root->left!=NULL){
        cout<<"L"<<root->left->data;
    }
    if (root->right!=NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
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

int main()
{
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
    root->left=node1;
    root->right=node2;
    printTree(root);
    delete root;

    BinaryTreeNode<int> * root2 = takeInputLevelWise();
    printTree(root2);
    delete root2;
    
    return 0;
}