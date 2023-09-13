#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode{
    T data;

    public:
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

int main()
{
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
    root->left=node1;
    root->right=node2;

    return 0;
}