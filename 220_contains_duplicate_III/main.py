"""
Follow-up of contain duplicate II:
    think of it as the exactly same case, in problem II we built a hashmap that memorizes all values appeared, now we want to build buckets with width t+1, then
    If |nums[i] - nums[j]| <= t, it is either:
    1) nums[i], nums[j] are in the same bucket
    or
    2) they are in adjacent bucket
    we use a hashmap to save the (bucket_id, val) pair, bucket_id can be computed as nums[i] / (t + 1)

    Note that we also need to remove overflowed elem at the end of each iteration to keep the size of sliding window unchanged

    Time: O(N)
    Space: O(k)


    Test Cases:
    1. []
    2. [-1,-1] -- negs
    3. [-1, 1] -- pos and negs
    4. k <= 0 or t < 0
"""
class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """
        if len(nums) <= 1 or t < 0 or k <= 0:
            return False
        d = {}
        bwidth = t + 1
        for i in xrange(len(nums)):
            bid = nums[i] / bwidth #compute the bucket id

            if bid in d:    #two elems are in the same bucket
                return True
            if (bid - 1) in d and abs(nums[i] - d[bid - 1]) <= t:
                return True
            if (bid + 1) in d and abs(nums[i] - d[bid + 1]) <= t:
                return True
            if i >= k and nums[i - k] / bwidth in d :
                del d[nums[i - k] / bwidth] #remove the first elem in the sliding window
            d[bid] = nums[i] #add new bucket id
        return False
                
            

        
sls = Solution()
l = [1,3,6,2]
print sls.containsNearbyAlmostDuplicate(l,1,2)
