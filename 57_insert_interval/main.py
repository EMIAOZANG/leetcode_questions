"""
keep max_end, and min_start for current interval
update when the non-overlapping intervals
"""
# Definition for an interval.
class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        m = []
#insert newInterval 
        for i in range(len(intervals)):
            if newInterval.start >= intervals[i]:
                intervals.insert(i,newInterval)
                break

        min_start = intervals[0].start
        max_end = intervals[0].end

        for i in intervals:
                 #we don't need to process intervals not overlapping with newInterval
            if i.end >= min_start or i.start <= max_end:
                max_end = max([i.end, newInterval.end])
                min_start = min([i.start, newInterval.start])
            else:
                m.append(Interval(min_start,max_end))
                min_start = i.start
                max_end = i.end

        m.append(Interval(min_start,max_end))
        return m

            


sls = Solution()
