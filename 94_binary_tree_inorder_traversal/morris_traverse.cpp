/*
 * Morris Traversal: Inorder
 * Idea:
 * Use an auxillary pointer pre, to find the previous node of current node, and connect current node with that previous node, once we have the connection, we could dive into the left subtree and repeat the steps.
 *
 * Starting from the root node:
 *
 * if curr->left == NULL:
 *    we output the current node and move to the right branch
 * if curr->left != NULL:
 *    start from pre = curr->left, 
 *    find pre = the first node without right child
 *    and then link pre->right = curr
 */
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
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> result;
      TreeNode* current = root;
      TreeNode* pre = NULL;
      while (current != NULL){
        if (current->left == NULL){
          result.push_back(current->val);
          current = current->right;
        }
        else {
          pre = current->left;
          while (pre != NULL && pre->right != NULL && current != pre->right){
            pre = pre->right;
          }
          if (pre->right == NULL) {
            //found the rightmost node in the left subtree
            pre->right = current;
            current = current->left; //move on to the left subtree
          }
          else {
            //restore threads
            pre->right = NULL;
            result.push_back(current->val);
            current = current->right;
          }
        }
      }
      return result;
    }
};

int main(){
  //test cases

}
