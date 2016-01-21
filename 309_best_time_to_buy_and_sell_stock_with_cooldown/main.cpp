//T+1 Buy-Sell Stock problem
//Classic DP method:
//first let maxProfit[i] = maxProfit[i-1], which means i is a cool down day,
//then for 
//maxProfit[i] = max(maxProfit[j-2]+(P[i]-P[j])) for all j=0 to i-1
//which indicates the last transaction is buy at j, then we only need to add the maxProfit gained till j-2
//
//Time Complexity: O(n^2)
//Space Complexity: O(n)
//
//*********************BOOOOOOOOM!**********************
//FSM method:
//******************************************************
//At each day i you could have 3 possible state:
// 1. You are holding the stock that day, which means you can sell, or continue to hold
// 2. You just sold out today, then you can only rest
// 3. You don't have any stock today, so you can buy or rest tomorrow
//
//Then you can draw the FSM with correct state transitions
//*Note that on the last day, we can not be in the state 1, since we cannot make more money by holding stock on last day
//for each day i:
//maxProfit_s1[i] = max(maxProfit_s3[i-1]-P[i],maxProfit_s1[i-1])
//maxProfit_s2[i] = maxProfit_s1[i-1]+P[i];
//maxProfit_s3[i] = max(maxProfit_s3[i-1], maxProfit_s2[i-1])
//
//Your initial value for each state will be:
//State 1: -P[0]
//State 2: -infinity, since you don't have anything to sell, impossible state
//State 3: 0 
//
//Time Complexity: O(n)
//Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:

    int maxProfit(vector<int>& prices){
      if (prices.size() < 2){
        return 0;
      }
      vector<int> MP({-prices[0],1<<31,0});
      vector<int> MP_prev;


      for (int i = 0; i < prices.size(); i++){
        MP_prev = MP;
        MP[0] = max(MP_prev[2]-prices[i],MP_prev[0]);
        MP[1] = MP_prev[0]+prices[i]; 
        MP[2] = max(MP_prev[2],MP_prev[1]);
      }
      return max(MP[1],MP[2]);
    }

    int maxProfit_DP(vector<int>& prices) {
        if (prices.size() < 2){
            return 0;
        }
        vector<int> maxProfit(prices.size(),0);
        for (int i = 1; i < maxProfit.size(); i++){
            for (int j = i-1; j >= 0; j--){
                int delta = prices[i]-prices[j];
                int prevProfit = (j>=2)?maxProfit[j-2]:0;
                maxProfit[i] = max(delta+prevProfit,maxProfit[i]);
            }
            maxProfit[i] = max(maxProfit[i],maxProfit[i-1]);
        }
        return *(maxProfit.rbegin());
    }
};

int main(){
    Solution sls;
    return 0;
}

