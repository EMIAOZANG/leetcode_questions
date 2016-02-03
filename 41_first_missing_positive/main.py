"""
Put each number to its right place, 
iterate through each item, if current number is not equal to the elem occupying the place it is supposed to be, swap this number to its deserved place
"""
class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in range(len(nums)):
            while nums[i] > 0 and nums[i] <= len(nums) and nums[i] != nums[nums[i]-1]:
                idx = nums[i]-1
                nums[i], nums[idx] = nums[idx], nums[i]
            
        for i in range(len(nums)):
            if nums[i] != i+1:
                return i+1
        return len(nums)+1
                
        
