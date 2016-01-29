"""
DFS versions, using GRAY node method in CLRS, if GRAY node is touched, it means cycle exists
Time: O(V+E)
Space: O(V+E)
"""
class Solution(object):
    def DFS_travel(self, G, node, marks):
        if marks[node] == 1:
            return False
        if marks[node] == 2:
            return True
#if current node hadn't been visited
        marks[node] = 1
        for dst in G[node]:
            if self.DFS_travel(G,dst,marks) == False:
                return False
        marks[node] = 2

    def DFS(self, G):
        marks = [0] * len(G)
        ret_state = True
        for src_node in range(len(G)):
            marks[src_node] = 1
            for dst_node in G[src_node]:
                if marks[dst_node] == 0:
                    ret_state = self.DFS_travel(G,dst_node,marks)
                    if ret_state == False:
                        return False
            marks[src_node] = 2
        return True

    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        graph = [[] for x in range(numCourses)]
#build graph
        for item in prerequisites:
            graph[item[0]].append(item[-1])

#DFS
        return self.DFS(graph)

sls = Solution()
P = [[0,1],[1,2],[0,2],[5,3],[3,4]]
P = [[0,1],[1,0]]
P = []
print sls.canFinish(0,P)

        
