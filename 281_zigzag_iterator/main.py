class ZigzagIterator(object):

    def __init__(self, v1, v2):
        """
        Initialize your data structure here.
        :type v1: List[int]
        :type v2: List[int]
        """
        self.ptrs = [0,0]
        self.ll = [v1,v2]
        self.pptr = 0 #pointer of ptrs

    def next(self):
        """
        :rtype: int
        """
        if self.ptrs[self.pptr] >= len(self.ll[self.pptr]):
            self.pptr = (self.pptr+1)%2
        if self.ptrs[self.pptr] < len(self.ll[self.pptr]):
            r = self.ll[self.pptr][self.ptrs[self.pptr]]
            self.ptrs[self.pptr] += 1
            self.pptr = (self.pptr+1)%2
            return r
            

    def hasNext(self):
        """
        :rtype: bool
        """
        return (self.ptrs[0] < len(self.ll[0])) or (self.ptrs[1] < len(self.ll[1]))

# Your ZigzagIterator object will be instantiated and called as such:
# i, v = ZigzagIterator(v1, v2), []
# while i.hasNext(): v.append(i.next())
