#include <iostream>
using namespace std;

#include <vector>
#include <queue>
template <typename T>

class treeNode {
    public:
    T data;
    vector<treeNode *> children;

    treeNode(T data){
        this->data=data;
    }
};

template <typename T>
treeNode<T> * takeInput(){
    cout<<"enter data : ";
    T rootData;
    cin >> rootData;
    treeNode<int> * root = new treeNode<int>(rootData);

    queue <treeNode<T>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        treeNode<T> * front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter no. of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;
        for (int i=0 ; i<numChild ; i++){
            int childData;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            treeNode<T> * child = new treeNode<T>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

template <typename T>
void printTree (treeNode<T> * root){

    if (root==NULL){
        return;
    }
    
    cout<<root->data<<" : ";
    for (int i=0 ; i<root->children.size() ; i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for (int i=0 ; i<root->children.size() ; i++){
        printTree(root->children[i]);
    }
}

int main()
{
    treeNode<int> * root = new treeNode<int>(1);
    treeNode<int> * node1 = new treeNode<int>(2);
    treeNode<int> * node2 = new treeNode<int>(3);

    root->children.push_back(node1);
    root->children.push_back(node2);

    printTree(root);

    treeNode<int> * root2 = takeInput<int>();
    printTree(root2);

    return 0;
}