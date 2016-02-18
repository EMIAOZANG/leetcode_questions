class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        s = ""
        while n > 0:
            s += chr((n-1)%26 + ord('A'))
            n = (n-1) / 26
        
        return s[::-1]
            
