class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """

        R = []
        if len(nums) == 0:
            return R
        nums.append(nums[-1])
        low = nums[0]
        for i in range(1,len(nums)):
            if nums[i] - nums[i-1] != 1:
                R.append(str(low)+'->' * (int(nums[i-1]-low > 0))+ str(nums[i-1])*(int(nums[i-1]-low > 0)))
                low = nums[i]
        return R
                
