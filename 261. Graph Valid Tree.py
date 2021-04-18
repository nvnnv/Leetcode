class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if n < 1:
            return False
        graph = {i:[] for i in range(n)}
        for e in edges:
            graph[e[0]].append(e[1])
            graph[e[1]].append(e[0])
        
        v = {}
        def dfs(i, k):
            if v.get(i) is not None:
                return False
            
            v[i] = 1
            f = True
            for j in graph[i]:
                if j != k:
                    f = f & dfs(j, i)
            return f
        
        f = dfs(0, -1)
        if f and len(v) == n:
            return True
        return False
