//
//  main.cpp
//  leetcode_112
//
//  Created by LuJiayi on 12/27/15.
//  Copyright © 2015 LuJiayi. All rights reserved.
//
#include <iostream>
#include <queue>
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
    
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL){
            //touching the bottom without finding
            return false;
        }
        if (root->left == NULL && root->right == NULL){
            //leaf node
            return ( sum-(root->val) == 0 );
        }
        //non-leaves
        return ( hasPathSum(root->left, sum-(root->val)) || hasPathSum(root->right, sum-(root->val)) );

    }
};

int main(){
    TreeNode* r = new TreeNode(1);
    TreeNode* ll = new TreeNode(2);
    r->left = ll;
    Solution sls;
    cout << sls.hasPathSum(r,1) << endl;
    return 0;
}
