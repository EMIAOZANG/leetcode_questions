#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
      if (m == n){
        return m;
      }
      int one_bitmap = ((1 << 31) + int(pow(2,ceil(log2(n-m+1))))-1);
      cout << one_bitmap << endl;
      cout << (1 << 31) << endl; 
      cout << one_bitmap << endl;
      int zero_bitmap = int(pow(2,floor(log2(m))));
      cout << zero_bitmap << endl;
      return (one_bitmap & zero_bitmap) & m; 
    }
};

int main(){
  int m = 0;
  int n = 0;
  Solution sls;
  while (cin >> m >> n){
    cout << sls.rangeBitwiseAnd(m,n) << endl;
  }
  return 0;
}
