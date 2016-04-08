/*
 * Classic Two Pointers
 * 
 * Solution:
 *
 * Recall: Bucket Theory: the height of water is decided by the shorter side
 * 
 * Therefore, we could use 2 pointers (left, right) to point to the current boundary of the container. Meanwhile, we keep record of the current Max Height
 * If the left boundary is taller, then we move the right pointer leftward, until we reached some bar taller than the tallest bar to the left of pointer [left],
 * Then we could switch to left side, and start to move left pointer right.
 *
 * During the moving, 
 * If we find a "ditch", we know the amount of water this ditch can hold equals min(max_left, max_right) - height[ditch], therefore we can update the total amount of water
 *
 * *******Little Trick that shines******:
 *
 * In order to process the bar at 0 and n-1 consistently, we assume that there are two bars at -1 and n with height -inf,
 * Then when the program starts, it will automatically update max_left and max_right to the height of bar 0 and n-1
 *
 * Time Complexity : O(n), since we never go back
 * Space Complexity : O(1), only need a few pointers
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
      if (height.size() <= 2) {
          return 0;
      }
      int left_max = 1 << 31;
      int right_max = 1 << 31;

      int left = -1;
      int right = height.size();

      int sum = 0;

      int min_bound = -1;
      int direction = 1;

      while (true) {
        //if leftMax is the smaller one, move left, otherwise move right               
        while (left < right && left_max <= right_max) {
          left++;
          if (height[left] < left_max) {
            sum += left_max - height[left];
          }
          else {
            left_max = height[left];
          }
        }

        while (right > left && right_max < left_max) {
          right--;
          if (height[right] < right_max) {
            sum += right_max - height[right];
          }
          else {
            right_max = height[right];
          }
        }
        if (left >= right) {
          break;
        }
      }
      return sum;
    }
};

int main(){
  int test[] = {0,1,0,2,1,0,1,3,2,1,2,1};
  vector<int> test_input(test, test+12);
  Solution sls;
  cout << sls.trap(test_input) << endl;
  return 0;
}
