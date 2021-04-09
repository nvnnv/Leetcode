class Solution:
    def smallestEquivalentString(self, A: str, B: str, S: str) -> str:
        if A is None or B is None or S is None:
            return None
        
        unionfind = {}
        def find(c):
            if unionfind.get(c) is None:
                return None
            f = unionfind[c]
            while f != unionfind[f]:
                f = unionfind[f]
            return f
        
        def union(a, b):
            fa = find(a)
            fb = find(b)
            if fa is None:
                unionfind[a] = a
                fa = a
            if fb is None:
                unionfind[b] = b
                fb = b
            unionfind[fa] = min(fa, fb)
            unionfind[fb] = min(fa, fb)
        
        for i in range(len(A)):
            union(A[i], B[i])
        
        s = ''
        for c in S:
            f = find(c)
            if f is None:
                unionfind[c] = c
                f = c
            s += f
        return s
        
        
