"""
very easy DP:
    numTrees[n] = sum_i=1_to_n(numTrees[i-1]+numTrees[n-i])
    numTrees[0] = 1
    numTrees[1] = 1
"""
class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        n_trees = [1] * (n+1)
        for i in range(1,n+1):
            n_trees[i] = sum([n_trees[j-1]*n_trees[i-j] for j in range(1,i+1)])
        return n_trees[n]

sls = Solution()
for i in range(1,10):
    print sls.numTrees(i)



