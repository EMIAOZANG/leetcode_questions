"""
DFS for edges, built a linked list representation for graph, for each dst add a boolean tag indicating whether the edge is visited, when all edges are visited return the result 

Note the trick we used to stop recursion

Time Complexity: O(E+ElgE) = O(ElgE)
"""

class Solution(object):
    def DFSVisit(self,G,v,L,remEdge):
        #print G
        if remEdge == 0:
            return L
        if v in G:
            for dst in G[v]:
                if dst[-1] == False:
                    L.append(dst[0])
                    dst[-1] = True #mark current edge as visited
                    if self.DFSVisit(G,dst[0],L,remEdge-1) != None:
                        return L #if the first edge is get return
                    dst[-1] = False
                    L.pop()
        return None
    
    def DFS(self,G,nE):
        l = ["JFK"]
        return self.DFSVisit(G,"JFK",l,nE)
        
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        from_to = {}
        numEdge = len(tickets)
        for ticket in tickets:
            try:
                from_to[ticket[0]].append([ticket[1],False])
            except:
                from_to[ticket[0]] = [[ticket[1], False]]
        for l in from_to.itervalues():
            l.sort() #sort destination array
        print numEdge, from_to
        return self.DFS(from_to,numEdge)

sls = Solution()
T = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
print sls.findItinerary(T)
        





