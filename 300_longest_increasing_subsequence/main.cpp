#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    //O(n^2) implementation
    int lengthOfLIS_binomial(vector<int>& nums) {
      if (nums.size() == 0){
        return 0;
      }
      vector<int> max_length(nums.size(),0);//initializing vector: vector<int> v(size,val);
      max_length[0] = 1;
      int curr_max = 0;
      for (int i = 1; i < nums.size(); i++){
        curr_max = 0;
        for (int j = 0; j < i; j++){
          if ((nums[j] < nums[i]) && (max_length[j] > curr_max)){
            curr_max = max_length[j];
          } 
        }
        max_length[i] = curr_max + 1;
      }
      return *max_element(max_length.begin(),max_length.end());
    }

    //BUGS still remaining!!!! Take care of this!!
    int lengthOfLIS_nlgn(vector<int>& nums) {
      if (nums.size() == 0){
        return 0;
      }
      int max_length = 1;
      priority_queue<int> q;
      q.push(nums[0]);
      for ( int i = 1; i < nums.size(); i++ ){
        cout << q.top() << " " << q.size() << endl; 

        while (!q.empty() && (q.top() >= nums[i])){
          q.pop();
        }
        q.push(nums[i]);
        if (q.size() > max_length){
          max_length = q.size();
        }
      }
      return max_length;
      

    }

};

int main(){
  int a[] = {10,9,2,5,3,7,101,18};
  vector<int> v(a,a+8);
  for (int i = 0; i< v.size(); i++ ){
    cout << v.at(i) << " ";
  }
  cout << endl;
  Solution sls;
  cout << sls.lengthOfLIS_nlgn(v) << endl;
  
  return 0;
}
