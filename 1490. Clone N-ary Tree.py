class Solution:
    def cloneTree(self, root: 'Node') -> 'Node':
        def copy(node):
            if node is None:
                return None
            
            node_c = Node(node.val, [])
            for n in node.children:
                node_c.children.append(copy(n))
            
            return node_c
        
        return copy(root)
