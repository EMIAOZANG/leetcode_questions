from collections import deque
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        serial_str = []
        if root == None:
            return ",".join(serial_str)
        q = deque()
        q.append(root)
        while len(q) > 0:
            head = q.popleft()
            if head == None:
                serial_str += ["null"]
            else:
                serial_str += [str(head.val)]
                q.append(head.left)
                q.append(head.right)
        while serial_str[-1] == "null":
            del serial_str[-1]
        return ",".join(serial_str)

    def buildTree(self, data, node_q):
        print data, node_q
        while len(data) > 0 and len(node_q) > 0:
            node = node_q.popleft()
            if len(data) > 0:
                left_str = data.popleft()
                if left_str != "null":
                    node.left = TreeNode(int(left_str))
                    node_q.append(node.left)
            if len(data) > 0:
                right_str = data.popleft()
                if right_str != "null":
                    node.right = TreeNode(int(right_str))
                    node_q.append(node.right)
        
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        str_list = data.strip().split(",")
        q = deque(str_list)
        fore_q = deque([])
        print q
        try:
            root = TreeNode(int(q.popleft()))
            fore_q.append(root)
        except:
            return None
        self.buildTree(q, fore_q) 
        return root


        
        

# Your Codec object will be instantiated and called as such:
codec = Codec()
print codec.deserialize("1,2,3,1,3,2,4")

