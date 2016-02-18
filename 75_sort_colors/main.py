class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """

        if len(nums) == 0:
            return 
        p0 = 0
        p2 = len(nums)-1

        while p0 < len(nums) and nums[p0] == 0:
            p0 += 1

        while p2 >= 0 and nums[p2] == 2:
            p2 -= 1

        if p0 > p2 or p0 >= len(nums) or p2 < 0:
#if there are only 0,2 or 0 or 2 in the list and they are sorted
            return
        
        p = p0
        while p0 < p2 and p <= p2:
            if nums[p] == 0:
                nums[p0], nums[p] = nums[p], nums[p0] #swapping
                p0 += 1
                while p < p0:
                    p += 1
            elif nums[p] == 2:
                nums[p2], nums[p] = nums[p], nums[p2]
                p2 -= 1
                while p > p2:
                    p -= 1
            else:
                p += 1 #when nums[p] == 1



        

        

