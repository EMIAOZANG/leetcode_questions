//Tag: Dynamic Programming(DP)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > & grid) {
      int n_cols = grid[0].size();
      int n_rows = grid.size();
      
      vector<vector<int> > S(n_rows, vector<int>(n_cols));
      S[0][0] = grid[0][0];

      //initialize the ridge
      for (int i = 1; i < n_rows; i++){
        S[i][0] = S[i-1][0] + grid[i][0];
      }

      for (int i = 1; i < n_cols; i++){
        S[0][i] = S[0][i-1]+grid[0][i];
      }

      //fill the matrix
      for (int i = 1; i < n_rows; i++){
        for (int j = 1; j < n_cols; j++){
          S[i][j] = min(S[i-1][j]+grid[i][j], S[i][j-1]+grid[i][j]); 
        }
      }

      return S[n_rows-1][n_cols-1];
    }
};

int main(){
  return 0;
}


