# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findClosestLeaf(self, root: TreeNode, k: int) -> int:
        if root is None:
            return -1
        
        ans =[(10000, root.val)]
        def dfs(n, d):
            if n.left is None and n.right is None:
                if n.val == k:
                    ans[0] = (0, k)
                return d, n.val
            
            l,r=111110,111110
            a1,a2=0,0
            if n.left is not None:
                l,a1 = dfs(n.left, d+1)
            if n.right is not None:
                r,a2 = dfs(n.right, d+1)
            
            if n.val == k:
                ans[0] = (min(l,r), (a1 if l < r else a2))
                return -1, -1
            if l < 0 or r < 0:
                if abs(l)+abs(r) < ans[0][0]:
                    if l<0:
                        ans[0] = (abs(l)+abs(r), a2)
                    else:
                        ans[0] = (abs(l)+abs(r), a1)
                if l < 0:
                    return -l-1, -1
                else:
                    return -r-1, -1
            return min(l,r),  (a1 if l < r else a2)
        dfs(root, 0)
        return ans[0][1]
                
