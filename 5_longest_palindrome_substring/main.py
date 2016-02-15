class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) == 0:
            return ""
        max_palindrome = ""
        max_start = 0
        max_end = 0
        for i in xrange(len(s)):
            j = 1
            if s[i] == s[i+j]:
                curr_max += 1
                j += 1
            if s[i] == s[i+j]:
                curr_max += 1
                j += 1
            while j > 2 and s[i] == 


