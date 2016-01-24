"""
O(n) solution using bucket sorting
let MAX, MIN be the max and min value of the array, then the max gap must be greater or equal to (MAX-MIN)/(N-1)
therefore we could set up N-1 buckets, and the max gap MUST BE interbucket gap, since all internal gaps are smaller than (MAX-MIN)/(N-1) 

Space complexity : O(N)
"""
class Solution(object):
    def min_max(self,arr):
        '''
        faster min/max algorithm, using only 3/2*n comparisons
        '''
        min = 1<<31
        max = -(1<<31)
        if len(arr) % 2 != 0:
            min = arr[0]
            max = arr[0]
        for i in range(0,len(arr)-1,2):
            if arr[i] > arr[i+1]:
                if max < arr[i]:
                    max = arr[i]
                if min > arr[i+1]:
                    min = arr[i+1]
            else:
                if max < arr[i+1]:
                    max = arr[i+1]
                if min > arr[i]:
                    min = arr[i]
        return min, max
        
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        #Bucket sort 
        if len(nums) == 0:
            return 0
        global_min, global_max = self.min_max(nums)
        if global_min == global_max:
            return 0
        diff = global_max-global_min

        max_gap = 0
        
        N = len(nums)
        diff = float((global_max-global_min))/(N-1)
        buckets = [[-(1<<31), (1<<31)] for x in range(N)] #max-min

        for item in nums:
            if item > buckets[int((item-global_min)/diff)][0]:
                buckets[int((item-global_min)/diff)][0] = item
            if item < buckets[int((item-global_min)/diff)][1]:
                buckets[int((item-global_min)/diff)][1] = item

        lower_bound = global_min
        upper_bound = buckets[0][1]

        for i in range(0,len(buckets)):
            if buckets[i][0] == -(1<<31):
                continue
            upper_bound = buckets[i][1] #upper-bound = min
            if upper_bound - lower_bound > max_gap:
                max_gap = upper_bound- lower_bound
            lower_bound = buckets[i][0]
        return max_gap


sls = Solution()
N = [1,1]


            

        


