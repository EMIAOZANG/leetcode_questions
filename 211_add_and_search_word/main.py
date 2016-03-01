"""
Classic Trie Tree implementation with simple wildcard matching
Note:
    1. Don't forget the isWord tag in TrieNode
    2. wildcard matching or regex matching should be implemented in recursive manner, for simplicity
    3. Beware of the position to start recursion, it should be the letter next to the current letter
Time complexity: add - O(N), N is the length of the longest word, search - O(N)
Space complexity: at most O(nN), imagine when all words are disjoint
"""

class TrieNode(object):
    def __init__(self,c = ""):
        self.ch = c #char 
        self.alphabet = {}
        self.isWord = False #isWord tag, True if the Node represents a actual word

class WordDictionary(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        #implement the data structure using a trie tree
        self.root = TrieNode()

    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: void
        """
        curr = self.root
        for c in word:
            try:
                curr = curr.alphabet[c]
            except:
                curr.alphabet[c] = TrieNode(c)
                curr = curr.alphabet[c]
        curr.isWord = True

    def dfs_search(self,root,word):
        """
        performs dfs searching for wildcard matching
        :type word: str
        :type root: TrieNode
        :rtype: bool
        """
        idx = 0
        for c in word:
            if c == ".":
                if len(root.alphabet) == 0:
                    return False
                else:
                    for val in root.alphabet.itervalues():
                        if self.dfs_search(val, word[idx+1:]):
                            return True
                    return False
            else:
                if c not in root.alphabet:
                    return False
                root = root.alphabet[c] #if there is a match keep searching downward
            idx += 1
        if root.isWord:
            return True
        return False
        
            
    def search(self, word):
        """
        Returns if the word is in the data structure. A word could
        contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        curr = self.root
        return self.dfs_search(curr, word) 


sls = WordDictionary()
sls.addWord('bad')
sls.addWord('mad')
sls.addWord('dad')
print sls.search('b..')
print sls.search('mad')
print sls.search('.ad')
print sls.search('..p')
        

# Your WordDictionary object will be instantiated and called as such:
# wordDictionary = WordDictionary()
# wordDictionary.addWord("word")
# wordDictionary.search("pattern")
