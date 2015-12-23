'''
python implementation of palindrome partitioning
WATCH OUT!!!!!
'''

import sys
import os

class Solution(object):
    def compute_palidrome(self, s):
        '''
        computes the palidrome identification matrix
        '''
#CAUTION: YOU SHOULD NEVER USE THE FOLLOWING INITIALIZATION, if you want independent nested list
#        P_ = [[True] * len(s)] * (len(s)+1) 
#USE the following format instead!!!
        P_ = [[True for x in range(len(s))] for y in range(len(s)+1)]
        for i in range(0,len(s)):
            P_[i][i] = True
            P_[i+1][i] = True
        
        for k in range(1,len(s)):
            for i in range(0,len(s)-k):
                P_[i][i+k] = (P_[i+1][i+k-1] == True) and (s[i] == s[i+k])
        return P_


    def add_partition(self,v,P_, stk, s, start):
        '''
        v: vector
        '''
#        print P_
#        print "start:" , start
#        print stk, len(stk)
        
        if start >= len(s):
            if len(stk) != 0:
                item = stk[:] #copying the memory
                v.append(item)
            return None

        for i in range(0,len(s)-start):
            if P_[start][start+i] == True:
                stk.append(s[start:start+i+1])
                self.add_partition(v,P_,stk,s,start+i+1)
                stk.pop()


    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        V = []
        sk = []

        P = self.compute_palidrome(s)
        self.add_partition(V,P,sk,s,0)

        return V

def main():
    sls = Solution()
    res = sls.partition("aaaab")
    print res

if __name__ == "__main__":
    main()


        
