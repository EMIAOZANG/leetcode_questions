'''
O(nlogn) : just use a hashtable to keep track of elem counts and sort the entire count array
O(n + klogk) : use a MIN HEAP to keep track of only the MAX K elements in the count array, take care of the code template down there
'''
import heapq
class Solution(object):
    '''
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        d = {}
        for x in nums:
            if x in d:
                d[x] += 1
            else:
                d[x] = 1
        #sort dictionary by values
        l = sorted(d, key=d.__getitem__)
        return l[-1:-k-1:-1]
    '''
        
    def topKFrequent(self, nums, k):
        """
        sub O(nlogn) method
        """
        d = {}
        for x in nums:
            if x in d:
                d[x] += 1
            else:
                d[x] = 1
        l = [(val, key) for key, val in d.iteritems()]
        h = [] #min heap of size k maintain the max k elems
        
        #reverse key, val pair as (val, key) pair, python heap sorts tuple by val -> key order by default
        #WATCH OUT THIS SECTION, it is a out-of-shelf way to get top k elements in n + klogk time
        for i in l:
            if len(h) >= k and i > h[0]:  
                heapq.heappop(h)
                heapq.heappush(h, i)
            elif len(h) < k or i > h[0]:
                heapq.heappush(h, i)
        result = []
        while len(h) > 0 and k > 0:
            result.append(heapq.heappop(h)[1])
            k -= 1
        return result
            
                
            
