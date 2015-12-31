//IDEA: Basic BFS, however, in this problem you have to use two counters to store the current number of nodes (posCount) and number of nodes in next level (nextLevelCount) and maintain them every time you FINISHED processing the node!
//
//Time Complexity: O(n)
//Space Complexity: O(n), which is the space of output array
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    void BFS(vector<vector<int> >& v, TreeNode* root){
      if (root == NULL){
        return;
      }

      queue<TreeNode*> q;
      q.push(root);

      int posCount = 1;
      int nextLevelCount = 0;
      int getCount = 0;
      vector<int> currentLevel;

      TreeNode* currentNode = NULL;
      while (!q.empty()){
        currentNode = q.front();
        q.pop();
        getCount++;

        currentLevel.push_back(currentNode->val); //append to current list
        //add two positions
        if ( currentNode->left != NULL){
          q.push(currentNode->left);
          nextLevelCount++;
        }
        if ( currentNode->right != NULL){
          q.push(currentNode->right);
          nextLevelCount++;
        }
        if ( posCount == getCount ){
          v.push_back(currentLevel); //if posCount+1 is a power of 2, then go to the next level
          currentLevel.clear();
          getCount = 0;
          posCount = nextLevelCount;
          nextLevelCount = 0;
        }



      }
      //get the remainder inside
      if (currentLevel.size() > 0){
        v.push_back(currentLevel);
      }
      
    }

    vector<vector<int> > levelOrderBottom(TreeNode* root) {
      vector<vector<int> > V;
      BFS(V,root);
      reverse(V.begin(),V.end());
      return V;
    }
};

int main(){
  return 0;
}
