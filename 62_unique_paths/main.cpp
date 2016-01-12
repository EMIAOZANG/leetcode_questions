//Very Easy DP, M[i,j] = M[i-1,j] + M[i,j-1], however, with iterative method we only need a 1-dimensional vector rowState and update from 1 to n-1 for each row
//
//Time Complexity:(O(mn))
//Space Complexity: O(n)
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
     
      vector<int> rowState(n,1);
      for (int i = 1; i < m; i++){
        for (int j = 1; j < n; j++){
          rowState[j] += rowState[j-1];
        }
      }
      return rowState[n-1];
    }
};

int main(){
  return 0;
}
