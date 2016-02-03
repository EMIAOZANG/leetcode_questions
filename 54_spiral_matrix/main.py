"""
Set a navigation vector array following order: right, down, left, up
starting from going right, when we cannot keep straight, make a right turn
if there is still no available routes after turning, we must arrived at the endpoint

Time Complexity : O(n)
Space Complexity : O(n)
"""
class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        arrows = [(0,1),(1,0),(0,-1),(-1,0)]
        compass_id = 0
        spiral = []
        try:
            #initialize visiting marks
            marks = [[True if x in range(1,len(matrix[0])+1) and y in range(1,len(matrix)+1) else False for x in range(len(matrix[0])+2)] for y in range(len(matrix)+2)]
            print marks
            
            #traverse
            i, j = 1, 1
            
            turn_count = 0
            while True:
                if marks[i][j] == True:
                    marks[i][j] = False
                    spiral.append(matrix[i-1][j-1])
                if turn_count >= 2:
                    break
                
                if marks[i+arrows[compass_id][0]][j+arrows[compass_id][-1]] == True:
                    i += arrows[compass_id][0]
                    j += arrows[compass_id][-1]
                    turn_count = 0   #reset turns for new node
                else:
                    #turn right once
                    compass_id = (compass_id + 1) % 4
                    turn_count += 1
            return spiral

        except:
            return []

sls = Solution()
L = [[ 1, 2, 3 ],[ 4, 5, 6 ],[ 7, 8, 9 ]]
print sls.spiralOrder(L)
