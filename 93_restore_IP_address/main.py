"""
Classic & Easy Backtracking, but take care of these special cases:
    1. section with leading 0 is not permitted, e.g. "01", "005"
    2. if the remaining length of substring is greater than 3*remaining sections, stop searching
"""
class Solution(object):
    def DFS(self, s, start, parsed, result):
        if start > len(s):
            return
        if len(parsed) >= 4:
            if len(parsed) == 4 and start == len(s):
                result.append(parsed[:]) #successfully parsed
            return 
        if 3*(4-len(parsed)) < len(s[start:]):
            return #the remaining string is too long to parse

        if len(parsed) < 4:
            for i in xrange(1,4):
                if start + i-1 < len(s) and int(s[start:start+i]) <= 255 and int(s[start:start+i]) >= 0 and ((len(s[start:start+i]) > 1 and s[start] != "0") or len(s[start:start+i])==1 ):
                    parsed.append(s[start:start+i])
                    self.DFS(s,start+i,parsed,result)
                    parsed.pop()

    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        R = []
        P = []
        self.DFS(s,0,P,R)
        R = [".".join(item) for item in R]
        return R

sls = Solution()
S = "25525511135"
S = "0000"
S = "19216801"
print sls.restoreIpAddresses(S)
         
