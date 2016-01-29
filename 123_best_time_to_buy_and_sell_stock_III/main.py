class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        ONE = 0
        TWO = 0
        prevONE = 0
        global_min_pos = 0
        local_min_pos = 0
        for i in range(1,len(prices)):
            print ONE,TWO,prevONE,global_min_pos,local_min_pos
            if prices[i]  < prices[i-1]:
                local_min_pos = i
                prevONE = ONE
            if prices[i] < prices[global_min_pos]:
                global_min_pos = i
            ONE = max([ONE,prices[i]-prices[global_min_pos]]) 
            TWO = max([prevONE+(prices[i]-prices[local_min_pos]),TWO])
        return max([ONE,TWO])

sls = Solution()
print sls.maxProfit([1,2,3,2,3,4,5,6,7,2,4,5,4,5,6,7,5])


        
