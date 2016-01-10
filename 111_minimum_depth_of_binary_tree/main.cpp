#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
      //use BFS, stop searching when the first leaf node is encountered
      queue<TreeNode*> q;
      int currentDepth = 0;
      int nextLevelCount = 0;
      if (root == NULL){
        return currentDepth;
      }
      q.push(root);
      currentDepth++;
      int currentLevelCount = 1;
      while (!q.empty()){
        root = q.front();
        q.pop();
        currentLevelCount--; //maintain number of nodes at current level
        if ((!root->left) && !(root->right)){
          //leaf node, return
          return currentDepth;
        }
        else{
          if (root->left){
            q.push(root->left);
            nextLevelCount++;
          }
          if (root->right){
            q.push(root->right);
            nextLevelCount++;
          }
        }
        //update depth and count info
        if (currentLevelCount == 0){
          //the last node of current level
          currentDepth++;
          currentLevelCount = nextLevelCount;
          nextLevelCount = 0;
        }
      }
      return 0;
    }
};

int main(){
  TreeNode* r = new TreeNode(1);
  TreeNode* curr = r;
  for (int i = 2; i <= 5; i++){
    curr->left = new TreeNode(2);
    curr = curr->left;
  }
  Solution sls;
  cout << sls.minDepth(r) << endl;

  return 0;
}
