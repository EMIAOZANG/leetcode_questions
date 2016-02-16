"""
Trie Tree Implementation
========================
TRIE Tree implementation, Trie Tree is a data structure used primarily for fast dictionary look-up (see http://songlee24.github.io/2015/05/09/prefix-tree/), we used a hashmap based implementation for all children here.

CAUTION: In order to distinguish path node and actual data node, we need a boolean flag isKey in every Trie Node.

Time Complexity for Insert, Search and StartsWith: O(h)
"""
class TrieNode(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.char = ''
        self.isKey = False #flag for actual key
        self.hashMap = {} #hash map for letter:
        
class Trie(object):

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        head = self.root
        for ch in word:
            try:
                head = head.hashMap[ch]
            except:
                head.hashMap[ch] = TrieNode()
                head.hashMap[ch].char = ch
                head = head.hashMap[ch]
        head.isKey = True

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        head = self.root
        for ch in word:
            if ch not in head.hashMap:
                return False
            head = head.hashMap[ch]
        #determine if head is a leaf node
        if head.isKey:
            return True
        return False

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie
        that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        head = self.root
        for ch in prefix:
            if ch not in head.hashMap:
                return False
            head = head.hashMap[ch]
        return True
            
# Your Trie object will be instantiated and called as such:
# trie = Trie()
# trie.insert("somestring")
# trie.search("key")
