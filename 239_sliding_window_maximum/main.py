"""
Using Deque to maintain the current sliding window max:

    Use a deque with val, key pairs and keep elems in descending order:
    e.g.
    l = [1,3,-1,3,5,3,6,7]
    m = 4
    then
    deque_[0-3] = [(3,3)]
    deque_[1-4] = [(5,4),(3,3)]
    deque_[2-5] = [(5,4),(3,5)]
    deque_[3-6] = [(6,5)] -- here we delete (5,4) because 6 is a bigger value that comes after 5, therefore 5 at position 4 cannot be the max when 6 is still in the array, this is IMPORTANT
    deque_[4-7] = [(7,6)]

    we describe the process as follows:
    1.for all sliding window, while the leftmost element in deque is smaller than current value or outside the range of current sliding window (garbage collection), pop it out
    2.while the rightmost value is smaller than current value or out of range, pop it out (since we want to keep the deque in descending order)
"""
from collections import deque

class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        if k <= 0 or len(nums) == 0:
            return []
        dq = deque([])
        L = [] #result
        #maintain a deque of (curr_max, idx) tuples, and keep the deque in descending order
        #build up for the first sliding window
        for i in xrange(min([len(nums),k])):
            while len(dq) > 0 and dq[0][0] <= nums[i]:
                dq.popleft()
            while len(dq) > 0 and dq[-1][0] < nums[i]:
                dq.pop()
            dq.append((nums[i], i)) #insert val-idx pair
        L.append(dq[0][0])

        #maintain the deque starting from the 2nd sliding window
        for i in xrange(k,len(nums)):
            while len(dq) > 0 and (dq[0][0] <= nums[i] or dq[0][1] <= i-k):
                dq.popleft()
            while len(dq) > 0 and (dq[-1][0] < nums[i] or dq[-1][1] <= i-k):
                dq.pop()
            dq.append((nums[i], i))
            L.append(dq[0][0])

        return L

sls = Solution()
l = [1,3,-1,3,5,3,6,7]
l = [1,3,1,2,0,5]
l = [5183,2271,3067,539,8939,2999,9264,737,3974,5846,-210,9278,5800,2675,6608,1133,-1,6018,9672,5179,9842,7424,-209,2988,2757,5984,1107,2644,-499,7234,7539,6525,347,5718,-742,1797,5292,976,8752,8297,1312,3385,5924,2882,6091,-282,2595,96,1906,8014,7667,5895,7283,7974,-167,7068,3946,6223,189,1589,2058,9277,-302,8157,8256,5261,8067,1071,9470,2682,8197,5632,753,3179,8187,9042,8167,4657,7080,7801,5627,7917,8085,928,-892,-427,3685,4676,2431,8064,8537,343,505,4352,2108,4399,66,2086,1922,9126,9460,393,443,5689,7595,850,8493,2866,732,3738,7933,3666,2370,5804,4045,7903,8009,5387,5542,7593,6862,1547,6934,-160,9693,4560,7429,9989,7232,-594,587,6476,9277,4471,5979,6268,2419,6706,-727,1927,7361,9684,5519,2703,1723,5181,3545,4290,9421,4288,1656,1541,9632,1448,-490,4747,5416,4139,-845,3834,3349,8594,7882,2279,7777,9369,9917,8167,6799,-612,5604,5787,2615,7033,5986,-322,8631,1793,-612,3528,206,419,1413,8585,5658,-981,1391,8088,7035,6259,-651,3118,9105,4531,2569,7576,7981,838,5715,1387,8506,331,7844,9187,6812,1221,6916,2361,5869,1002,5944,344,310,-981,3541,960,7667,8478,6610,9678,6511,3891]
print len(l)
print sls.maxSlidingWindow(l[:130],100)
