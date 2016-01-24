"""
Solve Recursively
e.g.
For this tree
       6
    5     4
  3   2  1  0
9      8 

We have
9 3 5 2 8 6 1 4 0 - inorder
9 3 8 2 5 1 0 4 6 - postorder

Then we start from the last node in postorder sequence, find it in inorder sequence, then we could get the size of the left and right branch

Time Complexity : O(n)
"""
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):

    def construct(self,inorder,postorder,in_left,in_right,post_left,post_right):
        if post_left > post_right:
            return None

        inorder_split = -1
        root = TreeNode(postorder[post_right])
        #find the position of root node in inorder tree
        for i in range(in_left,in_right+1):
            if inorder[i] == root.val:
                inorder_split = i
        left_size = inorder_split - in_left #size of the left branch
        right_size = in_right - inorder_split
        root.left = self.construct(inorder,postorder,in_left,in_left+left_size-1,post_left,post_left+left_size-1)
        root.right = self.construct(inorder,postorder,inorder_split+1,inorder_split+right_size,post_left+left_size,post_right-1)
        return root

    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        if len(inorder) <= 0:
            return None

        root = self.construct(inorder,postorder,0,len(inorder)-1,0,len(postorder)-1)
        return root

