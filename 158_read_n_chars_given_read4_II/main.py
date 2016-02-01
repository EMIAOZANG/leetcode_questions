# The read4 API is already defined for you.
# @param buf, a list of characters
# @return an integer
# def read4(buf):
from collections import deque

class Solution(object):
    def __init__(self):
        self.q = collections.deque()

    def read(self, buf, n):
        """
        :type buf: Destination buffer (List[str])
        :type n: Maximum number of characters to read (int)
        :rtype: The number of characters read (int)
        """
        idx = 0

        while True:
            tmpBuf = [""] * 4
            length = read4(tmpBuf)
            for i in range(length):
                self.q.append(tmpBuf.pop(0))
            while idx < n and self.q:
                    buf[idx] = self.q.popleft()
                    idx += 1
            if length < 4 or idx >= n:
                return idx
