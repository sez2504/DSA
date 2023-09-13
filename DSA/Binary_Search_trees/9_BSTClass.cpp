#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


#include <climits>

class BST {
    BinaryTreeNode<int> * root;

   public:
    BST() { 
        root = NULL;
    }

    ~BST(){
        delete root;
    }
	/*----------------- Public Functions of BST -----------------*/
    private:
    bool search(int data , BinaryTreeNode<int> * root){
        if (root==NULL){
            return false;
        }
        if (root->data==data){
            return true;
        }
        else if (data<root->data){
            return search(data,root->left);
        }
        else{
            return search(data,root->right);
        }
    }

    int minimum (BinaryTreeNode<int> * root){
    	if (root == NULL){
    		return INT_MAX;
    	}
    	return min(root->data , min(minimum(root->left) , minimum(root->right)));
    }

    BinaryTreeNode<int> * remove(int data , BinaryTreeNode<int> * root){
        if (root==NULL){
            return NULL;
        }
        if (data>root->data){
            remove(data , root->right);
            return root;
        }
        else if (data<root->data){
            remove(data , root->left);
            return root;
        }
        else {
            if (root->left==NULL && root->right == NULL){
                root=NULL;
                return NULL;
            }
            else if (root->left==NULL){
                BinaryTreeNode<int> * temp = root;
                temp=root->right;
                delete root;
                return temp;
            }
            else if (root->right==NULL){
                BinaryTreeNode<int> * temp = root;
                temp=root->left;
                delete root;
                return temp;
            }
            else{
                int new_data = minimum(root->right);
                //cout<<"new data : "<<new_data<<endl;
                root->data=new_data;
                root->right=remove(new_data , root->right);
                return root;
            }
        }
    }

    void printTree(BinaryTreeNode<int> * root){
        if (root==NULL){
            return;
        }
        cout<<root->data<<":";
        if (root->left!=NULL){
            cout<<"L:"<<root->left->data<<",";
        }
        if (root->right!=NULL){
            cout<<"R:"<<root->right->data;
        }
        cout<<endl;
        printTree(root->left);
        printTree(root->right);
    }

    BinaryTreeNode<int> * insert(int data , BinaryTreeNode<int> * root){
        if (root==NULL){
            BinaryTreeNode<int> * insertion = new BinaryTreeNode<int>(data);
            return insertion;
        }
        if ((data>root->data&&root->right==NULL)){
            BinaryTreeNode<int> * insertion = new BinaryTreeNode<int>(data);
            root->right=insertion;
            return root;
        }
        else if(data>root->data){
            insert(data , root->right);
            return root;
        }
        else if ((data<=root->data&&root->left==NULL)){
            BinaryTreeNode<int> * insertion = new BinaryTreeNode<int>(data);
            root->left=insertion;
            return root;
        }
        else if(data<=root->data){
            insert(data , root->left);
            return root;
        }
    }

    public:
    void remove(int data) { 
        root=remove(data , root);
        return;
    }

    void print() { 
        printTree(root);
    }

    void insert(int data) { 
        root=insert(data,root);
        return;
    }

    bool search(int data) {
		return search(data,root);
    }
};

int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}