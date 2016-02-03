"""
Very similar to 54
"""
class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        navigator = [(0,1),(1,0),(0,-1),(-1,0)]
        arrow = 0
        res = [[0 for x in range(n)] for y in range(n)]
        if n == 0:
            return []
        try:
            marks = [[True if x in range(1,n+1) and y in range(1,n+1) else False for x in range(n+2)] for y in range(n+2)]
        except:
            return []

        num = 1
        turn_count = 0
        i,j = 1,1
        while True:
            if marks[i][j] == True:
                marks[i][j] = False
                res[i-1][j-1] = num
            
            if turn_count >= 2:
                break
            
            if marks[i+navigator[arrow][0]][j+navigator[arrow][-1]] == True:
                i += navigator[arrow][0]
                j += navigator[arrow][-1]
                turn_count = 0
                num += 1
                
            else:
                arrow = (arrow + 1) % 4
                turn_count += 1
        return res
