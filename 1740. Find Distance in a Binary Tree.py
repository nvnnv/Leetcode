class Solution:
    def findDistance(self, root: TreeNode, p: int, q: int) -> int:
        if root is None or p == q:
            return 0
        
        f = [False]
        def dfs(node):
            if node is None:
                return 0
            
            left = dfs(node.left)
            right = dfs(node.right)
            if f[0]:
                return max(left, right)
            if left == 0 and right == 0:
                if node.val == p or node.val == q:
                    return 1
                return 0
            if left > 0 and right > 0:
                f[0] = True
                return left + right
            if left == 0 and right >0:
                if node.val == p or node.val == q:
                    f[0] = True
                    return right
                return right+1
            if left>0 and right ==0:
                if node.val == p or node.val == q:
                    f[0] = True
                    return left
                return left+1
        
        return dfs(root)
