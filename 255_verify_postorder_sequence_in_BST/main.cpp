//verify preorder sequence
//O(n) method:
//create a stack to simulate the traversal
//maintain a lowerBound value for the max value of the leftbranch + root,
//the only thing we need to verify is:
//
//Whereever we are on the right branch, the value must not be smaller than the lowerbound
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(vector<int>& preorder, int start, int end){
      //start end is inclusive
      if (start >= end){
        return true;
      }
      int pivot = -1;
      int i = start+1;
      int leftMax = 1 << 31; //-2^32
      int rightMin = ~( 1 << 31);
      //find the first element greater than preorder[start]
      for (i = start+1; i <= end && preorder[i] < preorder[start]; i++){
        if (preorder[i] > leftMax){
          leftMax = preorder[i];
        }
      }
      pivot = i;
      for (; i <= end; i++){
        //find the smallest in right branch
        if (preorder[i] < rightMin){
          rightMin = preorder[i];
        }
      }

      return (leftMax < preorder[start]) && (rightMin > preorder[start]) && (isValid(preorder, start+1, pivot-1)) && (isValid(preorder,pivot,end));
    }    

    bool isValidFast(vector<int>& preorder){
      stack<int> leftStk;
      int lowerBound = 1 << 31;  //lowerBound is the current max in the leftBranch, if any node in the right branch is smaller than this lower bound return false
      for (int i = 0; i < preorder.size(); i++){
        if (preorder[i] < lowerBound){
          return false;
        }
        while (!leftStk.empty() && preorder[i] > leftStk.top()){
          //entering a right branch node and left branch is not empty
          lowerBound = leftStk.top();
          leftStk.pop();
        }
        leftStk.push(preorder[i]);
      }
      return true;
    }

    bool verifyPreorder(vector<int>& preorder) {
      return isValidFast(preorder); 
    }
};


int main(){
  
  return 0;
}
