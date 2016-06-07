"""
Idea:
    keep track of the max sum that ends at i-th position, denoted by max_end[j]
    we have:

    max_end[j+1] = max(max_end[j] + nums[j+1], nums[j+1])
    
    then the answer is just the max of all max_ends

Time: O(n)
Space: O(n)
"""
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1:
            return nums[0]
        max_end = nums[0]
        max_now = nums[0]
        for item in nums[1:]:
            max_end = max([max_end + item, item]) #this means if sum[1,...i-1] < 0 we would throw it, otherwise we keep it
            max_now = max([max_end, max_now]) #this step ensures that we won't get a smaller max if current item < 0
        return max_now
        
