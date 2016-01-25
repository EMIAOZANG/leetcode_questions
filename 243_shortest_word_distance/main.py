"""
just set two pointers for each word and iterate through it one by one, keep updating distance at the same time
"""
class Solution(object):
    def shortestDistance(self, words, word1, word2):
        """
        :type words: List[str]
        :type word1: str
        :type word2: str
        :rtype: int
        """
        ptr_1 = -1
        ptr_2 = -1

        shortest_distance = 1 << 31
        for i in range(len(words)):
            if words[i] == word1:
                ptr_1 = i
            if words[i] == word2:
                ptr_2 = i
            if ptr_1 >= 0 and ptr_2 >= 0 and abs(ptr_1-ptr_2) < shortest_distance: 
                shortest_distance = abs(ptr_1-ptr_2)
        return shortest_distance

sls = Solution()
L = ["practice", "makes", "perfect", "coding", "makes","practice"]
print sls.shortestDistance(L,"coding","practice")

