class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def DFS(root, pathStr):
    if root == None:
        print "".join(pathStr)
    else:
        pathStr.append(root.val)
        DFS(root.left,pathStr)
        DFS(root.right, pathStr)
        pathStr.pop()

def solution(root):
    path = []
    DFS(root,path)


    
