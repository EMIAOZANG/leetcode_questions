//Moore's voting algorithm
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int count = 0;
      int key = 0;
      for (int i = 0; i < nums.size(); i++){
        if (count == 0){
          //all different pairs have been cleared
          key = nums[i];
          count = 1; //set current uncleared element as the new dominant element
        }
        else {
          if (key == nums[i]){
            count++;
          }
          else {
            count--;
          }
        }
      }
      return key;
    }

};

int main(){
  return 0;
}
