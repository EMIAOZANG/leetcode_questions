//classic non-recursive binary tree DFS
//
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
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> flattenedTree;
       stack<TreeNode*> traverseStk;

       while (root != NULL || !traverseStk.empty()){ //!CAUTION HERE
         while (root != NULL){
           flattenedTree.push_back(root->val);
           traverseStk.push(root);
           root = root->left;
         }
         if (!traverseStk.empty()){
           root = traverseStk.top();
           traverseStk.pop();
           root = root->right;
         }
       }
       return flattenedTree; 
    }
       
};

int main(){
  return 0;
}
