"""
Ugly numbers can be divided by 2,3 or 5
keep 3 pointers representing the current number that are going to be multiplied by 2,3,5 as L1,L2,L3
therefore, for any k-th ugly number, the k+1 th ugly number is the smallest of L1*2, L2*3, L3*5
2 2 2
3 3
5     
:  
1 2 3 4 5
"""
class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        pointers = {2:0,3:0,5:0}
        ugly_numbers = [1] * (n+1)
        for i in range(1,n):
            ugly_numbers[i] = min([key*ugly_numbers[pointers[key]] for key in pointers.iterkeys()])
            l = [key for key in pointers if key*ugly_numbers[pointers[key]] == ugly_numbers[i]]
            for key in l:
                pointers[key] += 1
        return ugly_numbers[-2] 

        
sls = Solution()
print sls.nthUglyNumber(12)
                    



