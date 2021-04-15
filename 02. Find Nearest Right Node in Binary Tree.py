# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findNearestRightNode(self, root: TreeNode, u: TreeNode) -> TreeNode:
        q = []
        q.append((root,1))
        while len(q) != 0:
            h,l = q.pop(0)
            if h.val == u.val:
                if len(q) != 0:
                    x, l1 = q.pop(0)
                    if l1 == l:
                        return x
                return None
            
            if h.left is not None:
                q.append((h.left,l+1))
            if h.right is not None:
                q.append((h.right, l+1))
        return None
