#include <iostream>
using namespace std;

#include <vector>
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
    return 0;
}