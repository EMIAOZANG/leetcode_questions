"""
Simple bottom-up DP Problem
"""
class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        try:
            l = triangle[-1][:]
            
            for i in range(-2,(0-len(triangle)-1),-1):
                for j in range(len(triangle[i])):
                    l[j] = min([l[j]+triangle[i][j],l[j+1]+triangle[i][j]])
            return l[0]
        except:
            return 0

sls = Solution()
L=[[2],[3,4],[6,5,7],[4,1,8,3]]
print sls.minimumTotal(L)
