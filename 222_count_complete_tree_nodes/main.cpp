//Complete Tree Nodes Count
//Make use of the property of Complete Trees
//1. Any Subtree of a complete tree is still complete
//2. Complete tree of height h has 2^(h-1) to 2^h-1 nodes
//
//We could then derive the recursive solution,
//
//Start from root, 
//First check if two branches have same height, if left tree is taller, then the last node must be in the left tree, if right tree and right tree are of same height (right tree could never be taller than left tree according to the property of complete trees), then the last node must be in the right tree
//
//After determining the location of the last node, we may pay attention to the following facts:
//1. if last node is in the right branch, then the left tree is full (has 2^(h_left)-1) nodes
//2. else, the right tree is full with height h_right (=h_left-1), and has 2^(h_right)-1 nodes
//
//Therefore, the tree has either 2^(h_right)+countNodes(root->left) or 2^(h_left)+countNodes(root->right) nodes
//
//Time Complexity: O(log n*log n) = O(h^2), at each level we need to go down to get tree depth
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int getTreeHeight(TreeNode* root){
      //get height of subtree, note that any subtree of as complete binary tree is still complete, therefore the height of the subtree is the height of the left branch
      if (root == NULL){
        return 0;
      }
      return 1+getTreeHeight(root->left);
    }

    int countNodes(TreeNode* root) {
      if (root == NULL){
        return 0;
      }
      int leftHeight = getTreeHeight(root->left);
      int rightHeight = getTreeHeight(root->right);

      if (leftHeight == rightHeight){
        return (1 << leftHeight) + countNodes(root->right);
      }
      else {
        return (1 << rightHeight) + countNodes(root->left);
      }
    }
};

int main(){
  return 0;
}
