'''
how to PASS BY REFERENCE using python:
    just use an mutable object, e.g. if you want to pass a reference, wrap the object in a list, and then pass the list as a function, then modify the object by list subsctription


IDEA:
    Consider 2 cases:
    1) if p has rightChild: then the successor is the leftmost node in the right subtree
    2) else: then the successor is the nearest parent along the search path who has right child

    thus we only need to record the nearest parent whose rightChild != None

Time Complexity: O(h)
Space Complexity: O(1)
'''
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def findInBST(self, root, p, last_p):
        if root == None:
            return None
        if root.val == p.val:
            return root
        elif root.val > p.val:
            last_p[0] = root
            return self.findInBST(root.left,p,last_p)
        else:
            return self.findInBST(root.right,p,last_p)

    def inorderSuccessor(self, root, p):
        """
        :type root: TreeNode
        :type p: TreeNode
        :rtype: TreeNode
        """
        successor = [None]
        if p.right != None:
            successor[0] = p.right
            while successor[0].left != None:
                successor[0] = successor[0].left

        else:
            self.findInBST(root,p,successor)
        return successor[0]



            

