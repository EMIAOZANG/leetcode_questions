"""
project on each axis, and binary search to get boundaries
"""
class Solution(object):

    def bin_search_left(self,arr,left,right):
        #right bound
        if left > right:
            return left
        mid = (left+right)/2
        if arr[mid] == 0.5:
            return mid
        if arr[mid] > 0.5:
            return self.bin_search_left(arr,left,mid-1)
        else:
            return self.bin_search_left(arr,mid+1,right)

    def bin_search_right(self,arr,left,right):
        if left > right:
            return right
        mid = (left+right)/2
        if arr[mid] == 0.5:
            return mid
        if arr[mid] > 0.5:
            return self.bin_search_right(arr,mid+1,right)
        else:
            return self.bin_search_right(arr,left,mid-1)

    def minArea(self, image, x, y):
        """
        :type image: List[List[str]]
        :type x: int
        :type y: int
        :rtype: int
        """
        #project to each axis
        try:
            rows = [0] * len(image)
            cols = [0] * len(image[0])

            for i in range(len(image[0])):
                rows = [(rows[j]|int(image[j][i])) for j in range(len(rows))]
            for i in range(len(image)):
                cols = [(cols[j]|int(image[i][j])) for j in range(len(cols))]


            #using binary search to locate the boundary
            left_bound_rows = self.bin_search_left(rows,0,x-1)
            right_bound_rows = self.bin_search_right(rows,x+1,len(rows)-1)
            left_bound_cols = self.bin_search_left(cols,0,y-1)
            right_bound_cols = self.bin_search_right(cols,y+1,len(cols)-1)
            print left_bound_rows,right_bound_rows
            print left_bound_cols,right_bound_cols

            return (right_bound_rows-left_bound_rows+1) * (right_bound_cols-left_bound_cols+1)
        except:
            return 0

sls = Solution()
L = ["0010","0110","0100"]
L = [list(i) for i in L]
print sls.minArea(L,0,2)
