/*
 IDEA: Recursive Greedy algorithm
 Find the closest point that could reach the endpoint
 if this point is reachable, then return true
 
 Ex.
 2 3 0 1 0
 
 canJump(n) = canJump(j), j could jump to n and j can be jumped from 1
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool traceJump(vector<int>& nums, int pos){
        if ( pos < 0 ){
            return false;
        }
        if ( pos == 0 ){
            return true;
        }
        int greedy_traceback = pos-1;
        while (greedy_traceback >= 0){
            if ( nums[greedy_traceback] >= pos-greedy_traceback ){
                break;
            }
            greedy_traceback--;
        }
        return traceJump(nums, greedy_traceback);
    }
    
    
    bool canJump(vector<int>& nums) {
        return traceJump(nums, nums.size()-1);
    }
};

int main(){
    Solution sls;
    sls.canJump(new vector<int>({0,1}))
    return 0;
}
