class DisjointSet:
    def __init__(self):
        self.parents = {}
        self.numElems = {}
        self.numSets = 0

    def Union(self, i, j):
        p_i = self.parents[i]
        p_j = self.parents[j]
        if p_i != p_j:
            if self.numElems[p_i] >= self.numElems[p_j]:
                self.parents[j] = self.parents[i] 
                self.numElems[i] += self.numElems[j]
                self.numElems[j] = self.numElems[i]
            else:
                self.parents[i] = self.parents[j] 
                self.numElems[j] += self.numElems[i]
                self.numElems[i] = self.numElems[j]
            self.numSets -= 1    

    def Find(self, i):
        if self.parents[i] != self.parents[self.parents[i]]:
            self.parents[i] = self.Find(self.parents[i])
        return self.parents[i]

    def Find_noR(self, i):
        p = self.parents[i]
        while (p != self.parents[p]):
            p = self.parents[p]
        temp = i
        temp_parent = self.parents[i] 
        #path compression
        while self.parents[temp] != p:
            self.parents[temp] = p
            temp = temp_parent
            temp_parent = self.parents[temp]
        return p

class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        ds = DisjointSet()
