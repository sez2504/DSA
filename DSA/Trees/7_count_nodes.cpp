#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};


void printLevelWise (TreeNode<int> * root){

    if (root==NULL){
        return;
    }
    
    //cout<<root->data<<":";
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty()){
        TreeNode<int> * front = pendingNodes.front();
        //cout<<"front : "<<front->children.size()<<endl;
        pendingNodes.pop();
        cout<<front->data<<":";
        int i;
        if (front->children.size()==0 && pendingNodes.empty()){
            break;
        }
        else if(front->children.size()==0){
            cout<<endl;
            continue;
        }
        for (i=0 ; i<front->children.size()-1 ; i++){
            cout<<front->children[i]->data<<",";
            pendingNodes.push(front->children[i]);
            //printLevelWise(root->children[i]);
        }
        if (front->children[i]!=NULL){
            cout<<front->children[i]->data<<endl;
            pendingNodes.push(front->children[i]);
        }
        else{
            break;
        }
    }
}

int numNodes (TreeNode<int>* root){
    int ans = 1;
    for (int i=0 ; i<root->children.size() ; i++){
        ans+=numNodes(root->children[i]);
    }
    return ans;
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    cout<<"Number : "<<numNodes(root)<<endl;
}