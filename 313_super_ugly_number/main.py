from heapq import *

class Solution(object):
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        ptrs = {item:0 for item in primes}
        ugly_numbers = [1] * (n+1)
        for i in range(1,n):
            ugly_numbers[i] = min([key*ugly_numbers[ptrs[key]] for key in ptrs])
            keys_to_update = [key for key in ptrs.iterkeys() if key*ugly_numbers[ptrs[key]] == ugly_numbers[i]]
            for key in keys_to_update:
                ptrs[key] += 1

        return ugly_numbers[-2]


sls = Solution()
P = [2, 7, 13, 19]
N = 12
print sls.nthSuperUglyNumber(N,P)
