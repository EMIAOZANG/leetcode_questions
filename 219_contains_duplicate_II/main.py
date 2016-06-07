"""
Use a hashtable to store the latest idx of each element.

Time: O(n)
Space: O(n)
"""
class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        d = {}
        for i in xrange(len(nums)):
            if nums[i] not in d:
                d[nums[i]] = i
            elif d[nums[i]] < i - k:
                d[nums[i]] = i
            else:
                return True
        return False
                
sls = Solution()
N = [1,3,4,1]
print sls.containsNearbyDuplicate(N, 3)
