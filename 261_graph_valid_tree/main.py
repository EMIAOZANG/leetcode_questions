class DisjointSet:
    def __init__(self,n):
        self.p = [x for x in range(n)]
        self.card = [1 for x in range(n)]
        self.n_sets = n

    def set_union(self,x,y):
        #weight balance
        if self.card[x] >= self.card[y]:
            self.p[y] = self.p[x]
            self.card[x] += self.card[y]
            self.card[y] = self.card[x] #don't forget updating cardinal
        else:
            self.p[x] = self.p[y]
            self.card[y] += self.card[x]
            self.card[x] = self.card[y]
        self.n_sets -= 1

    def set_find(self,x):
#path compression
        while self.p[x] != self.p[self.p[x]]:
            self.p[x] = self.set_find(self.p[x])
        return self.p[x]

class Solution(object):

    def validTree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: bool
        """
        dj = DisjointSet(n)
        for src, dst in edges:
            if dj.set_find(src) == dj.set_find(dst):

#which shows that they are already in the same tree
                return False
            else:
                dj.set_union(src,dst)
            
        return dj.n_sets == 1


sls = Solution()        
print sls.validTree(5,[[0,1],[2,1],[2,0],[2,4]])
