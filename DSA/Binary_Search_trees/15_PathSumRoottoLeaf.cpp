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
#include <cstring>

 void rootToLeafPathsSumToK(BinaryTreeNode<int> * root, int k,string ans) {
          if(k==root->data){      
              if(root->right==NULL&&root->left==NULL){
                 cout<<(ans+" "+char(root->data+48))<<endl;
                 return; 
              }else{
                  return;
              }
          }
         
        if(root->left!=NULL){
          if(ans=="")
            rootToLeafPathsSumToK(root->left ,k-root->data,ans+char(root->data+48));
           else{ 
            rootToLeafPathsSumToK(root->left ,k-root->data,ans+" "+char(root->data+48));
           }
        }
        if(root->right!=NULL){  
            if(ans=="")
            rootToLeafPathsSumToK(root->right ,k-root->data,ans+char(root->data+48));
           else{ 
            rootToLeafPathsSumToK(root->right ,k-root->data,ans+" "+char(root->data+48));
           }
        }
    }

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    if (root==NULL){
		return;
	}
	rootToLeafPathsSumToK(root,  k,  "");
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
    int k;
    cin >> k;
    rootToLeafPathsSumToK(root, k);
    delete root;
}