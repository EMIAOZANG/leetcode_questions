class Solution(object):
    def binarySearch(self,nums, l, r):
        if l >= len(nums)-2:
            return len(nums)-3
        if r <= 1:
            return 0
        mid = (l+r)/2
        if nums[mid] > nums[mid-1] and nums[mid] > nums[mid+1]:
            return mid-1
        elif nums[mid] > nums[mid-1] and nums[mid] < nums[mid+1]:
            return self.binarySearch(nums,mid+1,r)
        else:
            return self.binarySearch(nums,l,mid-1)
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return None
        nums.insert(0,-(1<<32))
        nums.append(-(1<<32))
    
        return self.binarySearch(nums,1,len(nums)-2)
        
sls = Solution()
N = [1,2,3,1,2,4,5]
N = []
N = [1]
N = [1,2,3,4,5]
N = [5,4,3,2,1,0]
print sls.findPeakElement(N)

