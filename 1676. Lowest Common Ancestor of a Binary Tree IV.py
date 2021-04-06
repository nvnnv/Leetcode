class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', nodes: 'List[TreeNode]') -> 'TreeNode':
        if root is None or len(nodes) == 0:
            return None
        
        v = {i.val: 1 for i in nodes}
        ansNode = []
        def dfs(node, c):
            if node is None:
                 return 0
            
            c = dfs(node.left, 0)
            c += dfs(node.right, 0)
            
            if v.get(node.val) is not None:
                c += 1
            if c == len(nodes) and len(ansNode) == 0:
                ansNode.append(node)
            return c
            
        dfs(root, 0)
        return ansNode[0]
