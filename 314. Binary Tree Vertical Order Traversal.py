# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import heapq as pq
class Solution:
    def verticalOrder(self, root: TreeNode) -> List[List[int]]:
        mapping = {}
        def dfs(root, index, level):
            if root is None:
                return
            
            if mapping.get(index) is None:
                mapping[index] = []
            mapping[index].append((level,root.val))
            
            dfs(root.left, index+1, level+1)
            dfs(root.right, index-1, level+1)
        
        dfs(root, 1,1)
        q = []
        for i, item in mapping.items():
            a = []
            item = sorted(item, key=lambda x: x[0], reverse=False)
            for pair in item:
                a.append(pair[1])
            heappush(q, (-i, a))
        ans = []
        while len(q)!= 0:
            ans.append(heappop(q)[1])
        return ans
