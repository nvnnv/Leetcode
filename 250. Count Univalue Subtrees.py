# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countUnivalSubtrees(self, root: TreeNode) -> int:
        if root is None:
            return 0
        
        ssum = [0]
        def dfs(node):
            if node.left is None and node.right is None:
                ssum[0] += 1
                return node.val
            
            left, right = node.val, node.val
            if node.left is not None:
                left = dfs(node.left)
            if node.right is not None:
                right = dfs(node.right)
            
            if left == node.val and right == node.val:
                ssum[0] +=1
                return left
            return -10011
        dfs(root)
        return ssum[0]
