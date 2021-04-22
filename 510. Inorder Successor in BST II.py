"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""

class Solution:
    def inorderSuccessor(self, node: 'Node') -> 'Node':
        if node is None:
            return None
        
        if node.right is None:
            if node.parent is None:
                return None
            while node.parent.right == node:
                node = node.parent
                if node.parent is None:
                    return None
            return node.parent
        
        x = [None]
        def dfs(n):
            if n.left is None:
                x[0] = n
                return
            dfs(n.left)
        
        dfs(node.right)
        return x[0]
