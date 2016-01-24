from heapq import *

class Solution(object):
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        h = []
        h.append(1)
        heapify(h)
        smallest = 0
        while len(h) != 0 and n > 0:
            smallest = heappop(h)
            for item in primes:
                if item*smallest not in h:
                    heappush(h,item*smallest)
            n -= 1
        return smallest

sls = Solution()
P = [2, 7, 13, 19]
N = 12
print sls.nthSuperUglyNumber(N,P)
