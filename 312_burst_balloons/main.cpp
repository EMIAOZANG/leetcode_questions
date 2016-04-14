/*
 * Burst Balloon
 * This is a classic problem belonging to the "Merge Stone DP problem" family.
 * 
 * Intuition: enumrating all permutations, this would end up with a exponential algorithm
 *
 * Further Observation: the max point that could be retrieved from burning all balloons from the i-th index to the j-th index will not be affected by how we burst balloons outside of it.
 * e.g.
 * 3,1,5,8,2,6
 * The max point acheivable by merging [1,5,8] has nothing to do with the external balloons (as long as the balloons outside remains unchanged when we are burning balloons from 1 to 8)
 * Therefore, let MP[i,j] be the maximum possible points we get by bursting all balloons between i to j, we can write the recursion as follows:
 *
 * MP[i,j] = max(MP[i,k-1] + n[i-1]*n[k]*n[i+1] + MP[k+1,j]), for all k = i,...,j, if i <= j
 * MP[i,j] = 0 if i > j
 *
 * k here is the last ballon to be bursted
 *
 * Now we compute MP in following order: 11, 22, ..., nn, 12,...,(n-1,n),..., (1,n)
 *
 * MP[1,n] is the max points we can get after bursting all balloons.
 *
 * For simpler implementation, we use a wrapper array with 1 boundary on both side to replace the original input array
 *
 * Time Complexity: O(n^3), in the outer loop, we compute the upper-left part of a n*n matrix, each inner loop is at most O(n)
 * Space Complexity: O(n^2)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
      vector<int> wrapper(nums.size() + 2, 1);
      for (int i = 1; i <= nums.size(); i++){
        wrapper[i] = nums[i - 1];
      }
      
      vector<vector<int> > max_points(wrapper.size() + 1, vector<int>(wrapper.size() + 1, 0));
      int max_value = 0;
      int current_value = 0;

      for (int i = 0; i < nums.size(); i++){
        for (int j = 1; j + i <= nums.size(); j++) {
          max_value = 0;
          for (int k = j; k <= j + i; k++) {
            max_value = max(max_points[j][k - 1] + max_points[k + 1][j + i] + nums[j - 1] * nums[k] * nums[j + i + 1], max_value); 
          }
          max_points[j][j + i] = max_value;
        }
      }

      return max_points[1][nums.size()];
    }
};

int main(){
  return 0;
}
