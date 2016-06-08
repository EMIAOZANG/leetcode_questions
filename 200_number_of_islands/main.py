"""
DFS or BFS or Union-Find

When using DFS, be ware of stackoverflow

Little Trick: Use extened matrix to 'wrap' the original array
"""
from collections import *
class Solution(object):

    def DFS_traverse(self, ext_grid, row, col):
        if row >= 0 and col >= 0 and row < len(ext_grid) and col < len(ext_grid[0]) and ext_grid[row][col] == '1':
            ext_grid[row][col] = '2' #visited
            for drow, dcol in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                self.DFS_traverse(ext_grid, row + drow, col + dcol)
        
    def DFS(self, ext_grid):
        num_islands = 0
        for i in xrange(len(ext_grid)):
            for j in xrange(len(ext_grid[0])):
                if ext_grid[i][j] == '1':
                    self.DFS_traverse(ext_grid, i, j)
                    num_islands += 1
                    #print i, j, ext_grid
        return num_islands

    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        #make ext_grid
        if len(grid) == 0 or len(grid[0]) == 0:
            return 0
        lt_grid = [['0' for i in xrange(len(grid[0]) + 2)]] 
        for i in xrange(len(grid)):
            lt_grid.append(['0'] + grid[i][:] + ['0'])
        lt_grid.append(['0' for i in xrange(len(grid[0]) + 2)])
        
        #print lt_grid
        
        #compute number of islands
        return self.DFS(lt_grid)
        
