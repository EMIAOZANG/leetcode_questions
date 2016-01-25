"""
Dynamic Programming with global max recorder:

Let MS[i,j] be the maximum size of square that ended at (i,j) ((i,j) is the bottom-right point)
Then we have:
    MS[i,j] = min(MS[i-1,j-1],MS[i,j-1],MS[i-1,j]) + 1, if left, up, left-up and matrix[i][j] itself are all 1
    MS[i,j] = 1, else

Then we could compute MS from top-left corner, and update the maximum square ever seen so far,

Time Complexity: O(n^2), needs to compute a O(n^2) matrix
Space Complexity: O(n), only need to store the previous line, and update from left to right, however, since we need MS[i-1,j-1], we have to keep an extra prev_left_up to store the previous left-up corner value
"""
class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        try:
            max_s = [0] * (len(matrix[0])) 
            max_s[0] = int(matrix[0][0])

            #init the first line
            for i in range(1,len(max_s)):
                max_s[i] = max(max_s[i-1],int(matrix[0][i]))
            max_square_size = max(max_s) #the global max_square size

            #compute the rest
            for i in range(1,len(matrix)):
                prev_val = max_s[0]
                #init the first value in each line
                max_s[0] = max(max_s[0],int(matrix[i][0]))
                #compute the rest values
                for j in range(1,len(max_s)):
                    temp = max_s[j]
                    if sum(map(int,[matrix[i][j-1],matrix[i-1][j],matrix[i-1][j-1],matrix[i][j]])) == 4:
                        #then we should add 1 if matrix[i][j] == 1
                        max_s[j] = min([max_s[j],max_s[j-1],prev_val])+1
                    else:
                        max_s[j] = int(matrix[i][j])
                    prev_val = temp
                    if max_square_size < max_s[j]:
                        max_square_size = max_s[j]
                max_square_size = max([max_square_size,max_s[0]])
            return max_square_size ** 2
        except:
            return 0

sls = Solution()
L = [["0","0","1","0","0"],["0","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
#L = [["0","1"]]
L = [[0],[1]]
L = ["101001110","111000001","001100011","011001001","110110010","011111101","101110010","111010001","011110010","100111000"]
L = [list(x) for x in L]
print sls.maximalSquare(L)

