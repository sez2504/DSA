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

int main()
{
    treeNode<int> * root = new treeNode<int>(1);
    treeNode<int> * node1 = new treeNode<int>(2);
    treeNode<int> * node2 = new treeNode<int>(3);

    root->children.push_back(node1);
    root->children.push_back(node2);
    return 0;
}