# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
        if root is None:
            return None
        
        q = []
        def dfs(x):
            if x is None:
                return []
            l=dfs(x.left)
            r=dfs(x.right)
            return l+[x]+r
        
        q = dfs(root)
        for i,j in enumerate(q):
            if j.val == p.val:
                if i == len(q)-1:
                    return None
                return q[i+1]
        return None
                
