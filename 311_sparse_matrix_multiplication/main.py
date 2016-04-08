"""
Sparse Matrix implementation (DOK)

Tricky problem, just pay attention to how sparse matrix multiplication is implemented
For simplicity, define mat2dic and dic2mat for list[list]<->dic{dic} conversions

Trick: In order to simplify the implementation, we can implement a helper function transpose, and compute line by line mat2dic(a).dot(mat2dic(b_T)) to avoid cross dictionary operations
"""
from itertools import *

class Solution(object):

    def transpose(self, X):
        X_T = [[0 for x in range(len(X))] for y in range(len(X[0]))]
        for row in range(len(X)):
            for col in range(len(X[row])):
                X_T[col][row] = X[row][col]
        return X_T
    
    def mat2dic(self, X, axis = 0):
        '''
        convert list of lists to sparse DOK representation
        '''
        d = {}
        for ridx, row in izip(count(0),X):
            line = {key:val for key, val in izip(count(0),row) if val != 0}
            if len(line) != 0:
                d[ridx] = line
            
        return d

    def dic2mat(self, D, n_rows, n_cols):
        l = [[0 for x in range(n_cols)] for y in range(n_rows)]
        for row in D.iterkeys():
            for col,val in D[row].iteritems():
                l[row][col] = val 
        return l

    def dot(self,da, db):
        dc = {}
        for row in da.iterkeys():
            product_row = {}
            for b_row in db.iterkeys():
                for col, val in da[row].iteritems():
                    if col in db[b_row]: 
                        try:
                            product_row[b_row] += val * db[b_row][col] #multiplying node
                        except:
                            product_row[b_row] = val * db[b_row][col]
            print product_row
            dc[row] = product_row
        return dc

    def multiply(self, A, B):
        """
        :type A: List[List[int]]
        :type B: List[List[int]]
        :rtype: List[List[int]]
        """
        if (len(A) == 0 or len(B) == 0 or len(A[0]) == 0 or len(B[0]) == 0):
            return []

        a = self.mat2dic(A)
        B = self.transpose(B)
        b = self.mat2dic(B)
        print 'A=', a
        print 'B=', b
        return self.dic2mat(self.dot(a,b),len(A),len(B[0]))

sls = Solution()
x = [[1,0,0],[-1,0,3]]
y = [[7,0,0],[0,0,0],[0,0,1]]
print sls.multiply(x,y)
        
         
