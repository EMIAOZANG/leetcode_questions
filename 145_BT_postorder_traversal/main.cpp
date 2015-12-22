#include <iostream>
#include <vector>
#include <stack>
#include <unistd.h>

using namespace std;

class TreeNode{
 public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
  vector<int> postorderTraversal(TreeNode* root) {
      vector<int> tree;
      if ( root != NULL ){
        vector<int> left_tree = postorderTraversal(root->left);
        vector<int> right_tree = postorderTraversal(root->right);
        tree.insert(tree.end(),left_tree.begin(),left_tree.end());
        tree.insert(tree.end(),right_tree.begin(),right_tree.end());
        tree.push_back(root->val); 
      }
      return tree; 
  }
  vector<int> postorderTraversal_iterative(TreeNode* root){
    vector<int> tree;
    return tree;
  }
};

int main(){

  return 0;
}
