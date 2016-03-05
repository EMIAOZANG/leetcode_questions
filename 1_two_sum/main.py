'''
sort and two pointers collision

Time Complexity: O(n)
'''
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums) <= 0:
            return None

        keymap = zip(nums, xrange(len(nums)))
        keymap.sort()
        left = 0
        right = len(keymap)-1
        while left < right:
            if keymap[left][0]+keymap[right][0] == target:
                return [keymap[left][-1],keymap[right][-1]]
            elif keymap[left][0]+keymap[right][0] < target:
                left += 1
            else:
                right -= 1
        return [keymap[left][-1],keymap[right][-1]]


sls = Solution()

