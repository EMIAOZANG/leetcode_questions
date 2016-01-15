//Easy enumeration using bit manipulation
//1.Sort the array in ascending order
//2.Consider the fact that the number of subsets of S is 2^|S|, therefore by using the binary number from 0 to 2^|S|-1 (==1 << |S|), we could enumerate all possible index combinations
//
//Time complexity: O(2^n)
//Extra Space: O(1)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
    
    
    vector<int> getSubset(vector<int>& nums, int subsetId){
        vector<int> subSet;
        subSet.clear();
        int idx = 0;
        while (subsetId > 0){
            if ((subsetId & 1) == 1){
                subSet.push_back(nums[idx]);
            }
            idx++;
            subsetId >>= 1; //move id right
        }
        return subSet;
    }
    
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > result;
        sort(nums.begin(),nums.end());//sort the array
        for (int i = 0; i < (1 << nums.size()); i++){
            result.push_back(getSubset(nums,i));
        }
        
        return result;
    }
};

int main(){
    int A[] = {3,1,2,4};
    vector<int> a(A,A+4);
    Solution sls;
    vector<vector<int> > res = sls.subsets(a);
    return 0;
}


