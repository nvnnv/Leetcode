class Solution:
    def findLeaves(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        
        hierarchy = []
        def dfs(node):
            if node is None:
                return 0
            
            left = dfs(node.left)
            right = dfs(node.right)
            
            d = max(left, right) + 1
            if len(hierarchy) < d:
                hierarchy.append([])
            hierarchy[d-1].append(node.val)
            return d
            
        
        dfs(root)
        return hierarchy
