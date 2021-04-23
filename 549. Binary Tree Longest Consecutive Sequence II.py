# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestConsecutive(self, root: TreeNode) -> int:
        if root is None:
            return 0
        
        graph = {}
        mapping = {}
        index = [0]
        def toG(node, fi):
            if node is None:
                return
            
            val = index[0]
            index[0]+=1
            mapping[val] = node.val
            graph[val] = []
            if fi != -1:
                graph[fi].append(val)
                graph[val].append(fi)
            toG(node.left, val)
            toG(node.right, val)
        
        toG(root, -1)
        l = [0]
        def dfs(i, fi, law, t):
            l[0] = max(l[0], t)
            for j in graph[i]:
                if j != fi:
                    if law == 0:
                        if mapping[j] - mapping[i] == 1:
                            dfs(j, i, 1, t+1)
                        if mapping[j] - mapping[i] == -1:
                            dfs(j,i,2, t+1)
                    if law == 1:
                        if mapping[j] - mapping[i] == 1:
                            dfs(j, i, 1, t+1)
                    if law == 2:
                        if mapping[j] - mapping[i] == -1:
                            dfs(j,i,2,t+1)
        
        for i in mapping.keys():
            dfs(i, -1, 0, 1)
        return l[0]
