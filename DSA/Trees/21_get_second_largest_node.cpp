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
/*alt:-\class helper {
  public :
    TreeNode<int>*  m;
    TreeNode<int>* sm;
    
    helper (TreeNode<int>* m, TreeNode<int>* sm) {
        this->m = m;
        this->sm = sm;
    }
};

helper help (TreeNode<int>* root) {
    if(root==NULL){
        helper r(NULL,NULL);
        return r;
    }
    helper ans(root, NULL);
    for (int i = 0; i < root->children.size(); i++) {
            helper child = help (root -> children[i]);  
            if(child.m->data > ans.m->data){
                if(child.sm==NULL){
                    ans.sm=ans.m;
                    ans.m=child.m;
                }
                else{
                    if(child.sm->data > ans.m->data){
                        ans.sm=child.sm;
                        ans.m=child.m;
                    }
                    else{
                       ans.sm=ans.m;
                        ans.m=child.m; 
                    }
                }
            }
        else {
            if(ans.m->data!=child.m->data && (ans.sm==NULL || child.m->data > ans.sm->data)){
                ans.sm=child.m;
            }
        }
        }
    return ans;
}

TreeNode <int>* getSecondLargest(TreeNode<int> *root) {
    
    if (root == NULL) return NULL;
    helper ans = help (root);
    return ans.sm;
}*/

template <typename T>
class Pair{
    public:
    int max;
    int secondMax;
    TreeNode<T> * secondMaxAns;
    TreeNode<T> * maxAns;
};

Pair<int> * getSecondLargestNode_helper(TreeNode<int>* root) {
    Pair<int> * p = new Pair<int>();
    if (root==NULL || root->children.size()==0){
        p->secondMaxAns=NULL;
        return p;
    }
    else{
        if (root->data>root->children[0]->data){
            p->max=root->data;
            p->maxAns=root;
            p->secondMax=root->children[0]->data;
            p->secondMaxAns=root->children[0];
        }
        else{
            p->secondMax=root->data;
            p->secondMaxAns=root;
            p->maxAns=root->children[0];
            p->max=root->children[0]->data;
        }
    }
    
    for (int i=1 ; i<root->children.size() ; i++){
        if (root->children[i]->data>p->max){
            p->secondMax=p->max;
            p->secondMaxAns=p->maxAns;
            p->max=root->children[i]->data;
            p->maxAns=root->children[i];
        }
        else if (root->children[i]->data>p->secondMax){
            p->secondMax=root->children[i]->data;
            p->secondMaxAns=root->children[i];
        }
    }
    
    for (int i=0 ; i<root->children.size() ; i++){
        Pair<int> * childAns = getSecondLargestNode_helper(root->children[i]);
        if (p->max > childAns->max){
            if (childAns->max > p->secondMax){
                p->secondMax=childAns->max;
                p->secondMaxAns=childAns->maxAns;
            }
        }
        else{
            if (p->max > childAns->secondMax){
                p->secondMax=p->max;
                p->secondMaxAns=p->maxAns;
                p->max=childAns->max;
                p->maxAns=childAns->maxAns;      
            }
            else{
                p=childAns;
            }
        }
        // if (root->children[i]->data>p->max){
        //     p->secondMax=p->max;
        //     p->max=root->children[i]->data;
        //     p->maxAns=root->children[i];
        //     p->secondMaxAns=p->maxAns;
        //     return p;
        // }
        // else if (root->children[i]->data>p->secondMax){
        //     p->secondMax=root->children[i]->data;
        //     p->secondMaxAns=root->children[i];
        //     return p;
        // }
        // else{
        //     return getSecondLargestNode_helper(root->children[i]);
        // }
    }
    return p;
}

TreeNode<int> * getSecondLargestNode(TreeNode<int> * root){
    return getSecondLargestNode_helper(root)->secondMaxAns;
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

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

}