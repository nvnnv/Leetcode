class Solution:
    def deleteTreeNodes(self, nodes: int, parent: List[int], value: List[int]) -> int:
        graph = {}
        for i, j in enumerate(value):
            graph[i] = [j]
        for i, j in enumerate(parent):
            if j != -1:
                graph[j].append(i)
        
        ans = [nodes]
        def dfs(i):
            
            a, b= graph[i][0], 1
            for j in graph[i][1:]:
                x, y= dfs(j)
                a += x
                b += y
            if a == 0:
                ans[0] -= b
                b = 0
            return a, b
        
        dfs(0)
        return ans[0]
