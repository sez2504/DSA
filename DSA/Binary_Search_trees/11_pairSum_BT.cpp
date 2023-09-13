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

using namespace std;

#include <vector>
#include <algorithm>

void convertBTtoArr(BinaryTreeNode<int> *root , vector<int> &output)
{
 if(root==NULL)
     return;
    
    output.push_back(root->data);
    convertBTtoArr(root->left,output);
    convertBTtoArr(root->right,output);
    
    
}


void nodesSumToS(BinaryTreeNode<int> *root, int sum) {

    vector<int> output;
    convertBTtoArr(root,output);
    sort(output.begin(),output.end());
    
    int i=0,j=output.size()-1;
    
    while(i<j)
    {
        
        if(output[i]+output[j]==sum)
        {
            cout<<output[i]<<" "<<output[j]<<endl;
            i++;
            j--;
        }
        
        else if(output[i]+output[j]>sum)
        {
            j--;
        }
        else
        {
            i++;
        }
        
        
    }  
}

void pairSum (BinaryTreeNode<int> * root , int sum){
	nodesSumToS(root,  sum);
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
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}