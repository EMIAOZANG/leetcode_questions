class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0 or len(nums) == 1:
            return None
        if len(nums) == 2 :
            if nums[0] == nums[1]:
                return nums[0]
            else:
                return None

        slow = 0
        fast = 0
#find a gcd == 1
        eta_1 = len(nums)-2
        eta_2 = len(nums)-1
        while True:
            if slow != fast and nums[slow] == nums[fast]:
                return nums[slow]
            slow = (slow + eta_1) % len(nums)
            fast = (fast + eta_2) % len(nums)






