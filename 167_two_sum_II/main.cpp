#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      vector<int> idx(2,1);
      idx[1] = numbers.size();

      while (idx[0] < idx[1]) {
        if (numbers[idx[0]-1] + numbers[idx[1]-1] < target) {
          idx[0]++;
        }
        else if (numbers[idx[0]-1] + numbers[idx[1]-1] == target) {
          return idx;
        }
        else {
          idx[1]--;
        }
      }
      return idx;
    }
};
