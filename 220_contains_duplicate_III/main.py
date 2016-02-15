class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """
        idx_l = [(val,idx) for idx, val in enumerate(nums)]    
        idx_l.sort()
        print idx_l

        for i in xrange(1,len(idx_l)):
           for i in  
sls = Solution()
l = [1,3,6,2]
print sls.containsNearbyAlmostDuplicate(l,1,2)
