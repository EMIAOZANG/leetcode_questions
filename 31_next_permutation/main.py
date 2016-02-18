"""
Idea:
    We observe the relationship between current permutation and next permutation
    1) if current permutation is completely reversed, it means it is the last permutation, so we only need to reverse it ("reset" the permutation to the initial case)
    2) Else, if current permutation is not the last one, then, e.g.
        2,5,4,3,1
        We need to find from right until we see the first ascend pair (nums[i] < nums[i+1])
        Note that at this point, the array after i contains ONLY REVERSED PAIRS, which means nums[i+1:] is non-increasing, nums[i+1] >= nums[i+2] >= ... >= nums[n]
        We then trace forward from i+1, and stop at the rightmost position j where nums[j] > nums[i] and |nums[j]-nums[i]| is the smallest for any j in [i+1,n] (Closest Bigger Property)
        Then we swap nums[i] and nums[j], since these two values are adjacent in sorted order, the non-increase property will HOLD in [i+1,...,n]
        Finally, we reverse nums[i+1,...,n], the reversed array must be the smallest after swapping (no reverse pair case is always smallest) 

Time Complexity: O(n)

"""
class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        #if the permutation is the last permutation (in descending order) 
        i = len(nums)-1
        while i > 0 and nums[i] <= nums[i-1]:
            i -= 1
        
        if i <= 0:
            nums[:] = nums[::-1]
            return
        else:
            i -= 1
            min_idx = i+1
            for j in xrange(i+1, len(nums)):
                if nums[j] <= nums[min_idx] and nums[j] > nums[i]: # WARNING: MUST USE <=, since < will stop at the leftmost qualifying position, this cannot guarantee nums[i+1,n] after replacement is strictly non-increasing
                    min_idx = j #find the smallest index at rightmost 
            nums[i], nums[min_idx] = nums[min_idx], nums[i] #swap nums[i] with the element that is next to it in ascending order
            #reverse the array after i+1, we don't need to worry whether reversed array is smallest since nums[i+1:n] is guaranteed to be in descending order
            nums[i+1:len(nums)] = nums[len(nums)-1:i:-1]

sls = Solution()
L = [1,2,3,4]
print sls.nextPermutation(L)
