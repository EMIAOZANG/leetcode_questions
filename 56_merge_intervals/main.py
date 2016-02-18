"""
classic Merge Interval problem, note the usage of attrgetter
Time complexity: O(n)
"""
from operator import attrgetter
class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if len(intervals) == 0:
            return intervals
        f = attrgetter('start') 
        intervals.sort(key=f) #sort by starting time

        l = []
        curr_interval = intervals[0]
        for x in range(1, len(intervals)):
            if intervals[x].start <= curr_interval.end:
                curr_interval.end = max([curr_interval.end,intervals[x].end])
            else:
                l.append(curr_interval)
                curr_interval = intervals[x]
        l.append(curr_interval)
        return l



        
