"""
DP with max area of histogram calculation

See this first:
    How to compute the largest rect area in a histogram
    http://www.geeksforgeeks.org/largest-rectangle-under-histogram/

    idea is here:
        |
      | | |   |
    | | | | | |
    1 2 3 2 1 2
    We only need to maintain the largest area of the rectangle bounded at right by current bar B[i] and at left by bars higher than current bar

Now we consider the matrix:
    we maintain a depth array and accumulate 1s in each column, such that the i-th elem in depths is the max depth of 1s in column i, thus we could transform the problem to something identical to the previous one
    we conly need to maintain an extra global max area value, and update it line by line

Time Complexity: O(n^2), n lines and one pass (O(n)) for each line
Space Complexity: O(n)
"""
class Solution(object):
    def find_current_largest_rectangle(self,D):
        D.append(0) #append a 0 at the end of array to clear up all bars
        idx_stk = []
        max_area = 0
        for i in range(len(D)):
            while len(idx_stk) > 0 and D[idx_stk[-1]] > D[i]:
                min_height = D[idx_stk.pop()]
                width = i if len(idx_stk) == 0 else i-idx_stk[-1]-1 #width is from prev node of the greater one to current
                
                max_area = max([max_area, min_height*width]) 
            idx_stk.append(i)
        return max_area

    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        try:
            depths = [0] * len(matrix[0])

            max_rect = 0
            for i in range(len(matrix)):
                depths = [(depths[j]+1)*int(matrix[i][j]) for j in range(len(matrix[i]))] 
                max_rect = max([max_rect,self.find_current_largest_rectangle(depths)]) #this step is O(n)
            
            return max_rect
        except:
            return 0

sls = Solution()
L = ["10100","10111","11111","10010"]
L = [list(item) for item in L]
