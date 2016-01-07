#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
      if (x < 0){
        return false;
      }
      if (x < 10){
        return true;
      }
      int y = 0;
      while (x > y){
        y = y * 10 + x%10;
        if ( y == 0){
            return false;  //when the last number is 0, return false
        }
        if (x == y){
          return true;
        }
        x /= 10;
        if ( x == y){
          return true;
        }
      }
      return false;
    }
};
