"""
Idea: 
    1. Binary filtering: build a set for n elems, at each time if set size is greater than 1, run knows(a,b) for random a and b
        we have:
        1) knows(a, b): a is not celebrity, put back b
        2) ~knows(a, b): b is not celebrity, put back a
        then at each round we could eliminate n/2 elemsm, and end up with only 1 elem t
        finally we run knows(t, i) for i in [1,...n) to determine if it is celebrity

    2. Linear search: if t is celebrity, then all nodes connects directly to t, so we only need to start from candidate = 0, and if knows(candidate, i), we set candidate to i, the final candidate must be a drain node
        then goes the same thing

    Time: O(n)
    Space: O(1)
"""
class Solution(object):
    def findCelebrity_binary(self, n):
        """
        :type n: int
        :rtype: int
        """
        possibles = set(range(n))

        while len(possibles) > 1:
            a = possibles.pop()
            b = possibles.pop()
            if knows(a, b):
                possibles.add(b) #put b back
            else:
                possibles.add(a)
        if len(possibles) == 1:
            t = possibles.pop()
            for i in range(n):
                if i != t and (knows(t,i) or not knows(i, t)):
                    return -1
            return t
        return -1
        
    def findCelebrity(self, n):
        candidate = 0
        for i in xrange(1, n):
            if knows(candidate, i):
                candidate = i
        for i in xrange(n):
            if i != candidate and (knows(candidate, i) or not knows(i, candidate)):
                return -1
        return candidate
