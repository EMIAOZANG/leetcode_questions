//Pay attention to NON-Recursive solution
//You DO NOT need a visited flag in non-recursive inorder traversal
#include <iostream>
#include <vector>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    void DFSNonRecursive(vector<int>& v, TreeNode* root){
        if ( root == NULL ){
            return;
        }
        stack<TreeNode*> nodeStack;
        
        while ( !nodeStack.empty() || root != NULL ){
            if ( root != NULL ){
                nodeStack.push(root);
                root = root->left;
            }
            else{
                root = nodeStack.top();
                //visit node
                v.push_back(root->val);
                nodeStack.pop();
                root = root->right; //visit right child tree
                
            }
        }
    }
    
    void DFS(vector<int>& v, TreeNode* root){
        if ( root != NULL ){
            DFS(v,root->left);
            v.push_back(root->val);
            DFS(v,root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> V;
        DFSNonRecursive(V,root);
        return V;
    }
};
