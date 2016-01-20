//Find the largest power of 3, and check n can be divided by this number
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
      return n > 0 && 1162261467 % n == 0 ;
    }

};

int main(){
  return 0;
}
