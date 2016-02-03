class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        min_idx = 0
        sum_profit = 0
        max_profit = 0
        for i in range(1,len(prices)):
            if prices[i] > prices[i-1]:
                max_profit = max([max_profit,prices[i]-prices[min_idx]])
            else:
                sum_profit += max_profit
                max_profit = 0
                min_idx = i
        sum_profit += max_profit
        return sum_profit
                

