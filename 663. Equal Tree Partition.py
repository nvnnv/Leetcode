# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def checkEqualTree(self, root: TreeNode) -> bool:
        if root is None:
            return False
        
        def sssum(n):
            if n is None:
                return 0
            a = n.val
            a+=sssum(n.left)
            a+=sssum(n.right)
            return a
        
        count = [sssum(root)]
        F = [0]
        def dfs(root):
            if root is None:
                return None
            
            left = dfs(root.left)
            right = dfs(root.right)
            if left is not None:
                if (count[0]-left) == left:
                    F[0] = 1
            if right is not None:
                if (count[0]-right) == right:
                    F[0] = 1
            return (left if left is not None else 0) +(right if right is not None else 0)+root.val
        dfs(root)
        return F[0] ==1
