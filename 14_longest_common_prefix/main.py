class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0:
            return ""
        i = 0
        while True:
            prefix = strs[0][0:i+1]
            for s in strs:
                if i >= len(s):
                    return s
                else:
                    if s[0:i+1] != prefix:
                        return s[0:i]
            i += 1
        return ""
                    
