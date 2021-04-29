# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestBSTSubtree(self, root: TreeNode) -> int:
        if root is None:
            return 0
        ans = [1]
        def dfs(n):
            if n is None:
                # min max ans
                return -10001, 10001, 0
            lmin,lmax, a1 = dfs(n.left)
            rmin,rmax, a2 = dfs(n.right)
            if a1 == -2 or a2 == -2:
                return 0,0,-2
            a = a1+a2+1
            if a1 == 0 and a2 == 0:
                return n.val,n.val,a
            if a1 == 0:
                if n.val < rmin:
                    ans[0] = max(ans[0], a)
                    return n.val, rmax, a
                return 0,0,-2
            if a2 == 0:
                if lmax < n.val:
                    ans[0] = max(ans[0], a)
                    return lmin, n.val, a
                return 0,0,-2
            if lmax < n.val < rmin:
                ans[0] = max(ans[0], a)
                return lmin, rmax, a
            return 0,0,-2
        _,_,a = dfs(root)
        return ans[0]
