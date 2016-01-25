"""
longest increasing path in a matrix
This is just a SKI Problem
"""
from heapq import *
class Solution(object):
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        #add frame to matrix
        try:
            M = [[1<<32 for i in range(len(matrix[0])+2)] for x in range(len(matrix)+2)] #original map
            LAS = [[1 for i in range(len(matrix[0])+2)] for x in range(len(matrix)+2)] #DP map


            for i in range(1,len(matrix)+1):
                for j in range(1,len(matrix[0])+1):
                    M[i][j] = matrix[i-1][j-1]

            #create heap ranked by values, small to large
            h = []
            heapify(h)
            for i in range(1,len(matrix)+1):
                for j in range(1,len(matrix[0])+1):
                    heappush(h,(M[i][j],(i,j)))

            
            #compute LAS
            offset = [(-1,0),(0,-1),(0,1),(1,0)]
            while len(h) > 0:
                val, (i,j) = heappop(h)
                LAS[i][j] = max([(LAS[i+offset_i][j+offset_j]+1)*int(M[i][j]>M[i+offset_i][j+offset_j]) for offset_i, offset_j in offset]+[LAS[i][j]])                    

            return max([LAS[m][n] for m in range(1,len(matrix)+1) for n in range(1,len(matrix[0])+1)])
        except:
            return 0

L = [[9,9,4],[6,6,8],[2,1,1]]
L = [[3,4,5],[3,2,6],[2,2,1]]
sls = Solution()
print sls.longestIncreasingPath(L)


            
         
