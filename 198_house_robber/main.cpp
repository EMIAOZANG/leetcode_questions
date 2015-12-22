#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
       if ( nums.size() <= 0 ){
         return 0;
       }
       else if ( nums.size() == 1 ){
         return nums.at(0);
       }
       vector<int> max_profit(nums.size(),0); 
       max_profit.at(0) = nums.at(0);
       max_profit.at(1) = max(nums.at(0), nums.at(1)); 
       for (int i = 2; i < max_profit.size(); i++){
         max_profit.at(i) = max(max_profit.at(i-2)+nums.at(i),max_profit.at(i-1));
       }
       return *max_element(max_profit.begin(), max_profit.end());

    }
};

int main(){
  int arr[8] = {5,3,1,7,2,4,6,8};
  vector<int> N(arr,arr+sizeof(arr)/sizeof(int));
  Solution sls;
  cout << sls.rob(N) << endl;
  return 0;
}
