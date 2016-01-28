"""
classic two pointers
"""
class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        left = 0
        right = -1
        dist = 1 << 32 
        try:
            sum = 0
        except:
            return 0
        while True:
            if sum >= s:
                dist = min([dist,right-left+1])
                if dist == 1:
                    return dist
            if sum <= s:
                right += 1
                if right >= len(nums):
                    break
                sum += nums[right]
            else:
                sum -= nums[left]
                left += 1
        if dist == 1 << 32:
            return 0
        return dist 

sls = Solution()
L = [1,2,3,4,5]
print sls.minSubArrayLen(15,L)

            

        
