"""
build a hashmap for each word and all of its indices in sorted order
e.g.
{"practice":[0],"makes":[1,4]}

Then every time we want to compute the min distance between two words, just compare the index lists like merging two sorted lists
"""
from heapq import *
class WordDistance(object):
    def __init__(self, words):
        """
        initialize your data structure here.
        :type words: List[str]
        """
        self._map = {}
        #build a dictionary of heaps
        for i in range(len(words)):
            try:
                self._map[words[i]].append(i)
            except:
                self._map[words[i]] = [i]
        #sort all map items
        for key,item in self._map.iteritems():
            item.sort()

        print self._map

    def shortest(self, word1, word2):
        """
        Adds a word into the data structure.
        :type word1: str
        :type word2: str
        :rtype: int
        """
        l1 = self._map[word1][:]
        l2 = self._map[word2][:]
        print l1, l2

        #sentinel
        l1.append(1<<32)
        l2.append(1<<32)

        ptr1 = 0
        ptr2 = 0

        shortest_dist = 1<<32
        
        while ptr1 < len(l1)-1 or ptr2 < len(l2)-1:
            shortest_dist = min([shortest_dist,abs(l1[ptr1]-l2[ptr2])])

            if l1[ptr1] < l2[ptr2]:
                ptr1 += 1
            else:
                ptr2 += 1

        return shortest_dist

# Your WordDistance object will be instantiated and called as such:
words = ["practice", "makes", "perfect", "coding", "makes"]
wordDistance = WordDistance(words)
print wordDistance.shortest("coding", "makes")
print wordDistance.shortest("practice", "coding")
