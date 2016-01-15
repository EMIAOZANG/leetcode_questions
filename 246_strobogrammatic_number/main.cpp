#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
      if (num.length() == 0){
        return true;
      }
      int pos = -1;
      int rpos = num.length();
      while (pos <= rpos){
        pos++;
        rpos--;
        if (num[pos] != num[rpos]){
          //unless it is 6 and 9
          if ((num[pos]=='9' && num[rpos]=='6') || (num[pos]=='6' && num[rpos]=='9')){
            continue;
          }
          return false;
        }
        //it must also be 0,1 or 8
        string sym = "018";
        if (!sym.find(num[pos])){
          return false; 
        }
      }
      return true;
    }
};

int main(){
  Solution sls;
  cout << sls.isStrobogrammatic("2");
  return 0;
}
