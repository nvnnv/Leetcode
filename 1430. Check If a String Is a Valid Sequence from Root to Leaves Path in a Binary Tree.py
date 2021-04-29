# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidSequence(self, root: TreeNode, arr: List[int]) -> bool:
        if root is None:
            return False
        
        def dfs(n, i):
            if n is None:
                return False
            if i >= len(arr):
                return False
            if n.left is None and n.right is None:
                if i == len(arr)-1 and n.val == arr[i]:
                    return True
                return False
            if n.val != arr[i]:
                return False
            
            l = dfs(n.left, i+1)
            r = dfs(n.right, i+1)
            return l | r
        return dfs(root,0)
