class Solution(object):
    def reverseWords(self, s):
        """
        :type s: a list of 1 length strings (List[str])
        :rtype: nothing
        """
        s[:] = " ".join(((''.join(s)).split(' '))[::-1]) #use s[:] to make sure you are modifying s itself instead of pointing s to a new address space

sls = Solution()
print sls.reverseWords(list("a b"))


