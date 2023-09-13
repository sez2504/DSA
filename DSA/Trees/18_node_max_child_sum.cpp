#include <iostream>
#include <queue>
#include <vector>
#include <climits>
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

template <typename T>
class Pair {
    public:
    int sum;
    TreeNode<T> * node;
};

/*int maxSumNode_helper(TreeNode<int>* root){
    if (root==NULL){
        return 0;
    }
    else if (root->children.size()==0){
        return root->data;
    }
    int sum=root->data;
    for (int i=0 ; i<root->children.size() ; i++){
        sum+=root->children[i]->data;
    }
    for (int i=0 ; i<root->children.size() ; i++){
        if (sum<maxSumNode_helper(root->children[i])){
            sum = maxSumNode_helper(root->children[i]);
        }
    }
    return sum;
}*/

Pair<int> * maxSumNode_helper(TreeNode<int>* root) {
    if (root==NULL){
        Pair<int> * p = new Pair<int>();
        p->sum=INT_MIN;
        p->node=NULL;
        return p;
    }
    else if (root->children.size()==0){
        Pair<int> * p = new Pair<int>();
        p->sum=INT_MIN+root->data;
        p->node=root;
        return p;
    }

    int sum = root->data;
    for (int i=0 ; i<root->children.size() ; i++){
        sum+=root->children[i]->data;
    }

    Pair<int> * ans = new Pair<int>();
    ans->node=root;
    ans->sum=sum;

    for (int i=0 ; i<root->children.size() ; i++){
        Pair<int> * childAns = maxSumNode_helper(root->children[i]);
        if (childAns->sum>ans->sum){
            ans=childAns;
        }
    }
    return ans;
}

TreeNode<int> * maxSumNode(TreeNode<int> * root){
    return maxSumNode_helper(root)->node;
}

// int maxSumNode_helper(TreeNode<int>* root){
//     if (root==NULL){
//         return 0;
//     }
//     else if (root->children.size()==0){
//         return root->data;
//     }
//     int sum=root->data;
//     for (int i=0 ; i<root->children.size() ; i++){
//         sum+=root->children[i]->data;
//     }
//     for (int i=0 ; i<root->children.size() ; i++){
//         if (sum<maxSumNode_helper(root->children[i])){
//             sum = maxSumNode_helper(root->children[i]);
//         }
//     }
//     return sum;
// }

// TreeNode<int>* maxSumNode(TreeNode<int>* root) {
//     if (root==NULL){
//         return root;
//     }
//     else if (root->children.size()==0){
//         return root;
//     }
//     int sum=root->data;
//     for (int i=0 ; i<root->children.size() ; i++){
//         sum+=root->children[i]->data;
//     }
//     int flag=-1;
//     for (int i=0 ; i<root->children.size() ; i++){
//         //cout<<"sum : "<<sum<<endl;
//         if (sum<maxSumNode_helper(root->children[i])){
//             flag=i;
//             sum = maxSumNode_helper(root->children[i]);
//             cout<<"sum : "<<sum<<endl;
//             cout<<"flag : "<<flag<<endl;
//         }
//     }
//     //cout<<"sum : "<<sum<<endl;
//     cout<<"root : "<<root->data<<
//     if (flag==-1){
//         return root;
//     }
//     cout<<"output : "<<root->children[flag]->data<<endl;
//     return root->children[flag];
// }

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

    TreeNode<int>* ans = maxSumNode(root);
    //int answer = maxSumNode_helper(root);

    // if (answer != 0) {
    //     cout << answer <<endl;
    // }

    cout<<ans->data<<endl;
}