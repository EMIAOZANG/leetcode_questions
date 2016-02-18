class Solution(object):
    def ch2int(self, ch):
        return ord(ch)-ord('A')+1
        
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        val = 0
        for i in xrange(len(s)-1,-1,-1):
            val += self.ch2int(s[i]) * (26**(len(s)-i-1))
        return val
        
