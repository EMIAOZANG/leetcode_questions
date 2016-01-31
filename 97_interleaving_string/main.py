"""
convert the problem to telling if a path is non-decreasing from bottom-left to top-right in a grid:
e.g.
s1
-----|--|--|--|------
    b|
-----|--|--|--|------
    b|
-----|--|--|--|------
    a|
-----|--|--|--|------
      a  b  c   s2
Then the problem is equivalent to find whether the path specified by s3 is non-decreasing from bot-left to top-right
Time Complexity: O(m*n)
"""
class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """

        if len(s3) != len(s1) + len(s2):
            return False
        is_int = [False] * (len(s2)+1)
#setting up the 0,0
        is_int[0] = True

        for i in range(1,len(is_int)):
            is_int[i] = is_int[i-1] == True and s2[i-1] == s3[i-1] 
        
        print is_int
        
        for j in range(1,len(s1)+1):
            is_int[0] = is_int[0] == True and s1[j-1] == s3[j-1]
            for k in range(1,len(is_int)):
                print j,k
#update is_int, either from left or from bottom of the grid
                is_int[k] = (is_int[k-1] == True and s2[k-1] == s3[j+k-1]) or (is_int[k] == True and s1[j-1] == s3[j+k-1])
            print is_int
        return is_int[-1]

sls = Solution()
print sls.isInterleave("aab","abc","abaabc")


        
        
