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
    def flipBinaryTree(self, root: 'Node', leaf: 'Node') -> 'Node':
        def dfs(node, leaf):
            if node is None:
                return None
            if node.val == leaf.val:
                node.right = node.left
                node.left = node.parent
                node.parent = None
                return node
            p1 = dfs(node.left, leaf)
            p2 = dfs(node.right, leaf)
            if p2:
                if node.parent is None:
                    node.right = None
                else:
                    node.right = node.left
                    node.left = node.parent
                node.parent = p2
                return node
            if p1:
                if node.parent is None:
                    node.left = None
                else:
                    node.left = node.parent
                node.parent = p1
                return node
            
            return None
        dfs(root, leaf)
        return leaf
            
            
