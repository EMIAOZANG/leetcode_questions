#include <iostream>
#include <vector>

using namespace std;

class Solution{
 public:
   int missingNumber(vector<int>& nums){
     int size = nums.size();
     long long sum = 0;
     for (int i = 0; i < size; i++){
       sum += nums.at(i);
     }
     long long c_sum = size*(size+1)/2; 
     return c_sum-sum;
     
   }
};

int main(){
  return 0;
}
