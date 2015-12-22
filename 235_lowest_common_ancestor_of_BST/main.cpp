/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      TreeNode* p_finder = root;
      TreeNode* q_finder = root;
      while ( p_finder != NULL && q_finder != NULL ){

        if ( (p_finder->val > p->val && q_finder->val > q->val) ){

          p_finder = p_finder->left;
          q_finder = q_finder->left;
        }
        else if (p_finder->val < p->val && q_finder->val < q->val){
          p_finder = p_finder->right;
          q_finder = q_finder->right;
        }
        else {
          //It is the lowest common ancestor
          return p_finder;
        }
      }
      return NULL;

    }
};

int main(){
  return 0;
}
