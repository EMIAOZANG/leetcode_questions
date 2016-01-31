class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        if len(nums) < 3:
            return []
#sort the array first
        nums.sort()
        print nums
        i = 0
        k = len(nums)-1
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            left_residual = 0-nums[i]
            j = i+1
            k = len(nums)-1
            while j < k:
                if nums[j] + nums[k] == left_residual:
                    print i, j, k
                    res.append([nums[i],nums[j],nums[k]])
                    while j < k and nums[j] == nums[j+1]:
                        j += 1
                    while j < k and nums[k] == nums[k-1]:
                        k -= 1
                    j += 1
                    k -= 1
                elif nums[j] + nums[k] > left_residual:
                    k -= 1
                else:
                    j += 1
        return res

sls = Solution()
L = [-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6]
print sls.threeSum(L)


            
                



