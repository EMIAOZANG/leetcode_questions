"""
Just treat it as a 1d array
"""
class Solution(object):
    def to2d(self, col_width, idx):
        return idx / col_width, idx % col_width
        
    def binarySearch(self, matrix, l, r, target):
        if l > r or l >= len(matrix[0]) * len(matrix) or r < 0:
            return False
        mid = (l + r) / 2
        i, j = self.to2d(len(matrix[0]), mid)
        if matrix[i][j] == target:
            return True
        elif matrix[i][j] > target:
            return self.binarySearch(matrix, l, mid - 1, target)
        else:
            return self.binarySearch(matrix, mid + 1, r, target)
    
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        m = len(matrix)
        if m == 0:
            return False
        n = len(matrix[0])
        if n == 0:
            return False
        L = m * n
        return self.binarySearch(matrix, 0, L-1, target)
        
