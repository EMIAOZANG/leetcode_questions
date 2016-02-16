class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def findTarget(self, root, target, pdsc):
        if root == None:
            return None
        if root.val == target:
            return root
        elif root.val > target:
            pdsc[-1] = root
            return self.findTarget(root.left, target, pdsc)
        else:
            pdsc[0] = root
            return self.findTarget(root.right, target, pdsc)

    def getPredSucc(self, root, target):
        pd_sc = [None, None] #last parent with [left, right] child
        p = self.findTarget(root, target, pd_sc)
        pred = pd_sc[0]
        succ = pd_sc[-1]
        if p != None:
            if p.right != None:
                succ = p.right
                while succ.left != None:
                    succ = succ.left
            if p.left != None:
                pred = p.left
                while pred.right != None:
                    pred = pred.right
        return pred, succ

    def closestKValues(self, root, target, k):
        """
        :type root: TreeNode
        :type target: float
        :type k: int
        :rtype: List[int]
        """
        res = []
        p, s = self.getPredSucc(root, target)
        while k > 0:
            if p == None:
                #leftmost elem
                res.append(s.val)
                for i in xrange(k-1):
                    target = s.val
                    p, s = self.getPredSucc(root, target)
                    res.append(s)
                    break
            if s == None:
                res.append(p.val)
                print 'here'
                for i in xrange(k-1):
                    target = p.val
                    p, s = self.getPredSucc(root, target)
                    res.append(p)
                    break
            if p != None and s != None:
                if abs(p-target) < s:
                    res.append(p.val)
                    p_new, s_new = self.getPredSucc(root, p.val)
                    p = p_new
                else:
                    res.append(s.val)
                    p_new, s_new = self.getPredSucc(root, s.val)
                    s = s_new
                k -= 1
        return res


        
         
