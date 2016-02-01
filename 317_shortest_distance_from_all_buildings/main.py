"""
Classic BFS, for each building, propagate distance and maintain a pathSum for the sum of distance,
Warning:
    MUST make sure the final point is reachable from every building, therefore we maintain a visit_times matrix for times of the node visited in each round of BFS
"""
from collections import deque

class Solution(object):
    def initMatrices(self, d, m, grid):
        
        for i in range(1,len(grid)+1):
            for j in range(1,len(grid[0])+1):
                if grid[i-1][j-1] > 0:
                    m[i][j] = False
                    d[i][j] = 1 << 32
#if current item is building add to the building list and modify d as 0
                    if grid[i-1][j-1] == 1:
                        d[i][j] = 0
                else:
                    m[i][j] = True
                    d[i][j] = 0
         

    def shortestDistance(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        offsets = [[-1,0],[1,0],[0,-1],[0,1]]
        try:
            #CAUTION: grid[i][j] should be grid[i-1][j-1]
            #initialize a visit mark matrix
            marks = [[False for i in range(len(grid[0])+2)] for j in range(len(grid)+2)]
            #init pathSum, dist 
            path_sum = [[1 << 32 for i in range(len(grid[0])+2)] for j in range(len(grid)+2)]
            dist = [[1 << 32 for i in range(len(grid[0])+2)] for j in range(len(grid)+2)]
            visit_sum = [[0 for i in range(len(grid[0])+2)] for j in range(len(grid)+2)]
            buildings = []

            for i in range(1,len(grid)+1):
                for j in range(1,len(grid[0])+1):
                    if grid[i-1][j-1] > 0:
                        marks[i][j] = False
                        path_sum[i][j] = 1 << 32
                        dist[i][j] = 1 << 32
#if current item is building add to the building list and modify dist as 0
                        if grid[i-1][j-1] == 1:
                            buildings.append([i,j])
                            dist[i][j] = 0
                    else:
                        marks[i][j] = True
                        path_sum[i][j] = 0
                        dist[i][j] = 0
#BFS from each building node
#            print marks
#            print path_sum
#            print dist
#            print buildings
            for b in buildings:
#reset marks, dist
                self.initMatrices(dist,marks,grid)

                q = deque([])
                q.append(b) #append starting point of BFS
                while len(q) > 0:
                    src_i, src_j = q.popleft()
                    path_sum[src_i][src_j] += dist[src_i][src_j] #updating pathSum
                    visit_sum[src_i][src_j] += 1

                    for ofs_i, ofs_j in offsets:
                        if marks[src_i+ofs_i][src_j+ofs_j] == True:
                            #mark as visited
                            marks[src_i+ofs_i][src_j+ofs_j] = False
                            #append to queue
                            q.append([src_i+ofs_i,src_j+ofs_j])
                            #update dist
                            dist[src_i+ofs_i][src_j+ofs_j] = dist[src_i][src_j] + 1

                
            #find min path sum
            min_sum = 1 << 32
            for i in range(1,len(grid)+1):
                for j in range(1,len(grid[0])+1):
#MUST make sure that every building can get to i,j
                    if path_sum[i][j] < min_sum and grid[i-1][j-1] == 0 and visit_sum[i][j] == len(buildings):
                        min_sum = path_sum[i][j]

            if min_sum < (1 << 32):
                return min_sum
            return -1
        except:
            return -1


sls = Solution()
G = [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]
G = [[1,0,0,2,0]]
G = [[0,2,1],[1,0,2],[0,1,0]]
print sls.shortestDistance(G) 

        





