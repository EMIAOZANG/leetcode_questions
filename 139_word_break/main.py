"""
classic Recursion search with pruning, for every word in wordDict, we attempt to find word in s, if word is in s, we recursively validate the left part and right part splitted by word

if none of the word combination can separate s, return False
"""
class Solution(object):
    def isBreakable(self,s,left,right,wordDict):
        '''
        [left, right)
        '''
        if left >= right:
            return True
        if s[left:right] in wordDict:
            return True
        for word in wordDict:
            start_pos = s[left:right].find(word)
            if start_pos >= 0:
                return self.isBreakable(s,left,left+start_pos,wordDict) and self.isBreakable(s,left+start_pos+len(word),right,wordDict)
        return False


    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: Set[str]
        :rtype: bool
        """
        true_val = False
        for word in wordDict:
            mid = s.find(word)
            if mid >= 0:
                true_val |= self.isBreakable(s,0,mid,wordDict) and self.isBreakable(s,mid+len(word),len(s),wordDict)
        return true_val

sls = Solution()
S = 'leetcode'
S = 'abcd'
D = set(['lee','code'])
D = ["a","abc","b","cd"]
S = "cars"
D = ["car","ca","rs"]
print sls.wordBreak(S,D)
        
