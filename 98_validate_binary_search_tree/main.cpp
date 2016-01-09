//Classic BST Validation
//Inorder DFS + BST
//Becareful of case when root->val = 1 << 31, use LONG INT instead!!!!
//Time Complexity: O(n)
#include <iostream>
#include <stack>
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
    bool isValidBST(TreeNode* root) {
      //use inorder traversal
      long prev = ((long)1 << 63); //make the init value the smallest int

      stack<TreeNode*> stk;
      while ( root != NULL || !stk.empty() ){
        while ( root != NULL ){
          stk.push(root);
          root = root->left;
        }
        if ( !stk.empty() ){
          root = stk.top();
          stk.pop();
          //visit here
          if ( (long)root->val <= prev ){
            return false;
          }
          else {
            prev = (long)root->val; //assign prev with the value of current node
          }
          root = root->right;
        }
      }
      return true;
    }
};

int main(){
  return 0;
}
