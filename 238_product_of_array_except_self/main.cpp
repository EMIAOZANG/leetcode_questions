//Simple Solution, Two Pass
//nums   1 2 3 4 5 6
//first pass: --> compute product[1...k-1]
//output 1 1 2 6 12 60
//second pass: <-- compute output[n] * product[k+1,...n]
//output 720 360 240 180 72 60
//
//Time complexity: O(n)
//Extra Space: 0
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int> output(nums.size(),1);
      for (int i = 1; i < output.size(); i++){
        output[i] = output[i-1]*nums[i-1];
      }
      int reverseProduct = 1;
      for (int i = output.size()-2; i >= 0; i--){
        reverseProduct *= nums[i+1];
        output[i] *= reverseProduct ;
      }
      return output; 
    }
};

int main(){
  return 0;
}
