"""
Single Number, very easy bit manipulation, see explanation for single number II
"""
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        counter = 0
        for i in xrange(len(nums)):
            counter ^= nums[i]
        return 0 | counter

