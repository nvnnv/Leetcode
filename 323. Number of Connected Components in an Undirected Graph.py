class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        unionfind = [i for i in range(n)]
        def find(x):
            while x != unionfind[x]:
                x = unionfind[x]
            return x
        def union(x, y):
            fx = find(x)
            fy = find(y)
            unionfind[fx] = min(fx, fy)
            unionfind[fy] = min(fx, fy)
        
        for i, j in edges:
            union(i, j)
        
        s = 0
        for i, j in enumerate(unionfind):
            if i == j:
                s+= 1
        return s
