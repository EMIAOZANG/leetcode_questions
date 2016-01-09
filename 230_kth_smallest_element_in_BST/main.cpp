//BST + Non-recursive DFS
//BST Property: Inorder Traverse Will Generate Ordered List
//Time Complexity: O(n)
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
    int inOrderDFS(TreeNode* root, int k){
      //use non-recursive in-order traversal
      stack<TreeNode*> stk;
      int count = 0;
      while (root != NULL || !stk.empty()){
        while (root != NULL){
          stk.push(root);
          root = root->left;
        }
        if (!stk.empty()){
          root = stk.top();
          stk.pop();
          //visit here
          count++;
          if (count == k){
            return root->val;
          }
          root = root->right;
        }
      }
      return 0;
    }

    int kthSmallest(TreeNode* root, int k) {
      return inOrderDFS(root,k); 
    }
};
