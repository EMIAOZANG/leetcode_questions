/*
 * "Longest Increasing Seuqence(LIS)" family problems
 * General Solution:
 *   We only need to maintain a vector min_end, min_end[i] is the current minimum value that could be the ending elem of a increasing sequence of max length i:
 *   e.g. 
 *   i 1 2 3 4 5 6 7 8
 *   v 5 4 2 3 6 8 4 10
 *   Then to figure out what is the length of LIS ending at current elem nums[j], we only need to find the rightmost min_end[i] < nums[j], then i+1 is the LIS length of nums[j],
 *   Later, we need to update min_end by set all min_end[k] > nums[j] to nums[j], by doing this we can guarantee each LIS length can be extended maximally
 *   e.g.
 *   current LIS = 1,2,8  current elem = 4, then we replace min_end[3] = 8 with 4, if 1,2,8,... is an IS, then 1,2,4,.....will be a longer IS
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
      int min_end_1 = ~(1 << 31); //min value that can form at maximum sequence of length 1
      int min_end_2 = ~(1 << 31); //min value that can form a increasing pair

      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > min_end_2) {
          return true;
        }
        if (nums[i] > min_end_1) {
          min_end_2 = nums[i];
        }
        else {
          min_end_1 = nums[i];
        }
      }
      return false;
    }
};
