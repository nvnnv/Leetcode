class Solution:
    def treeDiameter(self, edges: List[List[int]]) -> int:
        if len(edges) == 0:
            return -1
        
        graph = {}
        a = 999999
        b= 0
        for i, j in edges:
            if graph.get(i) is None:
                graph[i] = []
            if graph.get(j) is None:
                graph[j] = []
            graph[i].append(j)
            graph[j].append(i)
        
        dm = [(0, 0)]
        v = {}
        def dfs(i, d):
            v[i] = 1
            for j in graph[i]:
                if v.get(j) is None:
                    dfs(j, d+1)
            v[i] = None
            if dm[0][0] < d:
                dm[0] = (d, i)
        
        dfs(0, 0)
        dfs(dm[0][1], 0)
        return dm[0][0]
        
        
        
