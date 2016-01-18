//Variant of perfect squares
//How to improve running time:
//e.g.
//[1,2,5,10]
//27
//we only need to compute minCoins[num-coins[i]], where coins[i] <= sum
//Time complexity: O(mlgm)+O(mn)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

      if (amount == 0){
        return 0;
      }
      sort(coins.begin(),coins.end());
      
      //DP array
      vector<int> minCoins(amount+1,(1<<31));


      //Init DP array
      for (int i = 0; coins[i] <= amount && i < coins.size(); i++){
        minCoins[coins[i]] = 1;
      }
      //update DP array
      for ( int j = coins[0]+1; j <= amount; j++){
        for (int k = 0; k < coins.size() && coins[k] <= j; k++){
          //update minCoins[j] as the smaller value of itself and other combinations
          minCoins[j] = ((unsigned int)(minCoins[j-coins[k]]+1)<minCoins[j])?minCoins[j-coins[k]]+1:minCoins[j];
          //CAUTION: when comparing minCoins[j-coins[k]]+1 and minCoins[j], we use the unsigned version of minCoins[j-coins[k], since it's set to the maximum value of integers, and if we are using int, adding MAX_VALUE by 1 will produce a negative result
        }
      }

      return (minCoins[amount]>=0)?minCoins[amount]:-1; 
    }
};

