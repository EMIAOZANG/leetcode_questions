class NumMatrix(object):
    def __init__(self, matrix):
        """
        initialize your data structure here.
        :type matrix: List[List[int]]
        """
        try:
            self.s_matrix = [[0] * len(matrix[0]) for x in range(len(matrix))]
            self.s_matrix[0][0] = matrix[0][0]
	    for i in range(1,len(matrix)):
	        self.s_matrix[i][0] = self.s_matrix[i-1][0]+matrix[i][0]
	
	    for j in range(1,len(matrix[0])):
	        self.s_matrix[0][j] = self.s_matrix[0][j-1] + matrix[0][j]
	        
	    for i in range(1,len(matrix)):
	        for j in range(1,len(matrix[0])):
	            self.s_matrix[i][j] = matrix[i][j] + self.s_matrix[i-1][j] + self.s_matrix[i][j-1] - self.s_matrix[i-1][j-1]
        except:
            self.s_matrix = []



    def sumRegion(self, row1, col1, row2, col2):
        """
        sum of elements matrix[(row1,col1)..(row2,col2)], inclusive.
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        left = 0
        up = 0
        diag = 0
        if row1 != 0:
            up = self.s_matrix[row1-1][col2]
        if col1 != 0:
            left = self.s_matrix[row2][col1-1]
        if row1 != 0 and col1 != 0:
            diag = self.s_matrix[row1-1][col1-1]
        return self.s_matrix[row2][col2] - left - up + diag 


# Your NumMatrix object will be instantiated and called as such:
# numMatrix = NumMatrix(matrix)
# numMatrix.sumRegion(0, 1, 2, 3)
# numMatrix.sumRegion(1, 2, 3, 4)
