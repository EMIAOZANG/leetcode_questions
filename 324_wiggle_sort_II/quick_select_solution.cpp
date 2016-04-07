#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    void wiggleSort(vector<int>& nums) {
      //Find median
      auto median_it = nums.begin() + nums.size() / 2;
      nth_element(nums.begin(), median_it, nums.end());
      
      //interleave lower and upper halves
      for (int i = 1; i < nums.size() / 2; i += 2){
        swap(nums[i], nums[nums.size() / 2 + i]);
      } 
    }
};
