"""
Specialized binary search, offers different behavior when dealing with integers and floats
Floats:
    if target is not found, return the next right position
Integers:
    if target is not found, return -99 as an identifier

Procedure:
    1.Search Target
    2. If target not found return [-1,-1], else return [search(target-0.5),search(target+0.5)+1]
"""
class Solution(object):
    def binary_search(self, nums, target, left, right):
        if left > right:
            if target /1 == target:
                return -99
            return left
        mid = (right+left)/2
        if nums[mid] == target:
            return mid
        elif nums[mid] > target:
            return self.binary_search(nums,target,left,mid-1)
        else:
            return self.binary_search(nums,target,mid+1,right)

    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if self.binary_search(nums,target,0,len(nums)-1) == -99:
            return [-1,-1]
        l = [self.binary_search(nums,target-0.5,0,len(nums)-1), self.binary_search(nums,target+0.5,0,len(nums)-1)]
        return l
