"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""

class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if root is None:
            return None
        head = [None]
        def dfs(node, d):
            if node is None:
                return None
            
            l = dfs(node.left, 1)
            if head[0] is None:
                # head[0] = Node()
                # head[0].right = node
                head[0] = node
            r = dfs(node.right, 2)

            if l is not None:
                l.right = node
                node.left = l
            if r is not None:
                node.right = r
                r.left = node
            if d == 1:
                n = node
                while n.right is not None:
                    n = n.right
                return n
            if d == 2:
                n = node
                while n.left is not None:
                    n = n.left
                return n
            return node
        dfs(root, 0)
        x = head[0]
        while x.right is not None:
            x = x.right
        x.right = head[0]
        head[0].left = x
        return head[0]
                
