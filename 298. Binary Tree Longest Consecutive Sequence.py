# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestConsecutive(self, root: TreeNode) -> int:
        if root is None:
            return 0
        
        l = [0]
        # law = 1 means increasing
        # only increasing sequence
        def dfs(node, val, t, law):
            l[0] = max(t, l[0])
            if node is None:
                return
            
            if val is None:
                dfs(node.left, node.val, t+1, 0)
                dfs(node.right, node.val, t+1, 0)
                return
            if law == 0:
                if node.val-val == 1:
                    dfs(node.left, node.val, t+1, 1)
                    dfs(node.right, node.val, t+1, 1)
                else:
                    dfs(node.left, node.val, 1, 0)
                    dfs(node.right, node.val, 1, 0)
            if law == 1:
                if node.val-val == 1:
                    dfs(node.left, node.val, t+1, 1)
                    dfs(node.right, node.val, t+1, 1)
                else:
                    dfs(node.left, node.val, 1, 0)
                    dfs(node.right, node.val, 1, 0)
            
        dfs(root, None, 0, 0)
        return l[0]
                    
