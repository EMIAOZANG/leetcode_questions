class Solution(object):
    def isStrobogrammatic(self, num):
        """
        :type num: str
        :rtype: bool
        """
        i = 0
        j = len(num)-1
        while i <= j:
            if not num[i]+num[j] in '00,11,88,696':
                return False
            i += 1
            j -= 1
        return True

#test block 
sls = Solution()
print sls.isStrobogrammatic('2')
