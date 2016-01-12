//Simple DP
//Can be Solved using only O(n) extra space, special care to the first row initialization
//1 0 0 0 0 -> 0 0 0 0 0
//0 0 0 1 0 -> 1 1 1 0 0
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
      if (obstacleGrid.size() == 0){
        return 0;
      }
      vector<int> rowState(obstacleGrid[0]);
      //Initialize the first row
      int occupation = 0;
      for (int i = 0; i < obstacleGrid[0].size(); i++){
        if ( obstacleGrid[0][i] == 1 )
        {
            occupation = 1;
        }
        rowState[i] = 1 - occupation; 
      }
      //Update each row
      for (int i = 1; i < obstacleGrid.size(); i++){
        if (obstacleGrid[i][0] == 1){
            rowState[0] = 0;
        }
        for (int j = 1; j < obstacleGrid[0].size(); j++){
	        if ( obstacleGrid[i][j] != 1 ){
	          rowState[j] += rowState[j-1];
	        }
          else{
            rowState[j] = 0;
          }
        }
      }
      return rowState[obstacleGrid[0].size()-1];
    }
};

int main(){
  return 0;
}
