class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        dic = {')':'(',']':'[','}':'{'}
        stk = []
        for i in range(len(s)):
            if s[i] == '(' or s[i] == '{' or s[i] == '[':
                stk.append(s[i])
            else:
                if len(stk) == 0 or stk[-1] != dic[s[i]]:
                    return False
                stk.pop() 
        if len(stk) > 0: #don't forget to check if there are remaining items in the stack
            return False
        return True
