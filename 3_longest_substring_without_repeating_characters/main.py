class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        lastSeen = {}  
        if len(s) <= 0:
            return 0
        j = 0
        i = 0
        longest = -(1 << 32)
        while i < len(s):
            while j < len(s):
                #print i, j, lastSeen
                if s[j] in lastSeen:
                    if lastSeen[s[j]] >= i: #the elem is repeated in s[i,j]
                        if longest < j-i: #check if this is the longest substring
                            longest = j-i
                            print longest
                        i = lastSeen[s[j]]+1 #move left margin
                        lastSeen[s[j]] = j
                        j += 1
                        break
                 #the elem is brand new
                lastSeen[s[j]] = j
                j += 1
            if j >= len(s):
                if longest < j-i:
                    longest = j-i
                break
                
        return longest
                


