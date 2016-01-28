class Solution(object):
    def eigenVector(self,s):
        try:
            l = [0] * len(s)
            count = 0
            dic = {s[0]:0}
            for i in range(len(s)):
                if not s[i] in dic:
                    count += 1
                    dic[s[i]] = count
                l[i] = dic[s[i]]
            return l
        except:
            return []

    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        return self.eigenVector(s) == self.eigenVector(t) 

sls = Solution()
print sls.isIsomorphic("ab","bb")
         
