class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        try:
            rowIndex += 1

            P = [1] * (rowIndex) #=4
            L = [1]

            for i in range(1,rowIndex):
                for j in range(1,rowIndex-i):
                    P[j] = P[j] + P[j-1]
                L.append(P[rowIndex-i-1])
            return L

        except:
            return []

         
sls = Solution()
k = 2
print sls.getRow(k)
