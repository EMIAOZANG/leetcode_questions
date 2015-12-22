#include <iostream>
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

    void DFS(TreeNode* curr, int prev_val, int prev_len, int& max_len){
      if (curr != NULL){
        int length = 1;
        if (curr->val == prev_val + 1){
          length = prev_len + 1;

        }

        if ( max_len < length){
          max_len = length;
        }

        DFS(curr->left, curr->val, length, max_len);
        DFS(curr->right, curr->val, length, max_len);
      }
    }

    int longestConsecutive(TreeNode* root) {
      //stores the maximum length
      int max_length = 0;
      DFS(root,-99999,1,max_length);

      return max_length;
    }
};

int main(){
  stack<int> s;
  return 0;
}
