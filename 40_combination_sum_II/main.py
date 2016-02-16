"""
Pruning Ahead of Time:
    Consider the following cases:
    1) the sum is equal or greater than target -> pop elem out
    2) current element is equal to the element just popped out from the list, then we cannot do the search again
"""
class Solution(object):
    def traverse(self, candidates, results, currList, currSum, pos, target):
        if currSum >= target:
            if currSum == target:
                results.append(currList[:])
            return
        i = pos+1
        while i < len(candidates) and currSum + candidates[i] <= target:
            #jump over duplicates
            currList.append(candidates[i])
            self.traverse(candidates, results, currList, currSum+candidates[i], i, target)
            last = currList.pop()
            while i >= 0 and i < len(candidates) and candidates[i] == last:
                i += 1
            if i >= len(candidates):
                break
        


    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        if len(candidates) <= 0:
            return []
        candidates.sort()
        R = []
        l = []
        i = 0
        while i < len(candidates) and i < len(candidates) and candidates[i] <= target:
            l.append(candidates[i])
            self.traverse(candidates, R, l, candidates[i], i, target)
            last = l.pop()

            while i >= 0 and i < len(candidates) and candidates[i] == last:
                i += 1
            if i >= len(candidates):
                break
        return R

sls = Solution()
C = [10,1,2,7,6,1,5]
T = 8
print sls.combinationSum2(C, 8)
