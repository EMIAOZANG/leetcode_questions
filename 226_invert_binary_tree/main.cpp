#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void invert(TreeNode* root){
      if (root != NULL){
        TreeNode* temp = NULL;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        invert(root->left);
        invert(root->right);
      }
      

    }
    
    TreeNode* invertTree(TreeNode* root) {
      invert(root);
      return root;
    }
};
