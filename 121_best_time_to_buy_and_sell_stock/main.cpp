//just keep the min value prior to current position, and then update maximum profit by comparing current max profit and a[i]-prevMin
//
//Time Complexity: O(n)
//Space Complexity: O(1)
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prevMin = ~(1 << 31);
        int maxProfit = 0;
        for ( int i = 0; i < prices.size(); i++){
            if (prices[i] < prevMin){
                prevMin = prices[i];
            }
            if (prices[i]-prevMin > maxProfit){
                maxProfit = prices[i]-prevMin;
            }
        }
        return maxProfit;
    }
};
