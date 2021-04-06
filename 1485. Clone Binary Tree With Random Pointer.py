# Definition for Node.
# class Node:
#     def __init__(self, val=0, left=None, right=None, random=None):
#         self.val = val
#         self.left = left
#         self.right = right
#         self.random = random

class Solution:
    def copyRandomBinaryTree(self, root: 'Node') -> 'NodeCopy':
        mapping = {}
        
        def copy(node, index):
            if node is None:
                return None
            
            node_c = NodeCopy(node.val)
            node_c.left = copy(node.left, index*2-1)
            node_c.right = copy(node.right, index*2)
            mapping[node] = node_c
            return node_c
        
        def update(node_c, node):
            if node is None:
                return
            
            if node.random is not None:
                node_c.random = mapping[node.random]
            
            update(node_c.left, node.left)
            update(node_c.right, node.right)
            
        r = copy(root, 0)
        update(r, root)
        return r
        
