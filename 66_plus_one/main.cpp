//Simplified BigInt Sum
//Time Complexity: O(n)
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int upgrade = 0;
      for (int i = digits.size()-1; i >= 0; i--){
        digits[i] = (digits[i] + 1 + upgrade) % 10;
        upgrade = (digits[i] + 1 + upgrade) / 10;
      }
      if (upgrade == 1){
        digits.insert(digits.begin(),1);
      }
      return digits;
    }
};

int main(){
  int a[] = {9,9,9,9,9};
  vector<int> A(a,a+5);
  Solution sls;
  vector<int> res = sls.plusOne(A);
  return 0;
}
