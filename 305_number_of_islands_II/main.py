
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
                self.parents[p_j] = p_i 
                self.numElems[p_i] += self.numElems[p_j]
            else:
                self.parents[p_i] = p_j 
                self.numElems[p_j] += self.numElems[p_i]
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
    
    def to1DIndex(self, m, n, position):
        return position[0] * n + position[1] #compute the 1d idx of point(i,j)

    def numIslands2(self, m, n, positions):
        """
        :type m: int
        :type n: int
        :type positions: List[List[int]]
        :rtype: List[int]
        """
        ds = DisjointSet()
        L = []
        ofs = [[0,1], [0,-1], [1,0], [-1,0]]
        for point in positions:
#add new points
            ds.parents[self.to1DIndex(m,n,point)] = self.to1DIndex(m,n,point)
            ds.numElems[self.to1DIndex(m,n,point)] = 1
            ds.numSets += 1
#check and merge surrounding points
            for d in ofs:
                if self.to1DIndex(m,n,[point[0]+d[0],point[1]+d[1]]) in ds.parents:
                    ds.Union(self.to1DIndex(m,n,point),self.to1DIndex(m,n,[point[0]+d[0], point[1]+d[1]])) #union two points
            L.append(ds.numSets)
        return L

sls = Solution()
m = 1
n = 6
p = [[0,1],[0,2],[0,4],[0,3]]
print sls.numIslands2(m,n,p)


                    

            
         
