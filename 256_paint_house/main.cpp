#include <iostream>
#include <vector>
#include <algorithm>

//very basic DP practice problem

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int> >& costs) {
      if (costs.size() == 0){
        return 0;
      }
      //declaring 2d array for memorizing min cost
      vector<vector<int> > min_cost(costs.size(),vector<int>(3,0)); 
      
      //initial condition
      min_cost[0] = costs[0];

      int n = costs.size();
      for (int i = 1; i < n; i++){
        for (int j = 0; j < 3; j++){
          //use (j+1)%3 and (j+1)%3 to select indexes except 3
          min_cost[i][j] = costs[i][j] + min(min_cost[i-1][(j+1)%3],min_cost[i-1][(j+2)%3]);
        }
      }

      return *min_element(min_cost[n-1].begin(),min_cost[n-1].end());

    }
};

int main(){
  vector<vector<int> > test_array(3,vector<int>(3,0)); 
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++ ){
      cin >> test_array[i][j];
    }
  }
  Solution sls;
  cout << sls.minCost(test_array) << endl;
  
  return 0;
}
