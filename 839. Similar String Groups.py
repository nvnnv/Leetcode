class Solution:
    def numSimilarGroups(self, strs: List[str]) -> int:
        def simi(a,b):
            if len(a) != len(b):
                return False
            c = 0
            for i in range(len(a)):
                if a[i] != b[i]:
                    c+=1
            return c <= 2
        
        rank = [1 for i in strs]
        uf = [i for i in range(len(strs))]
        def union(x,y):
            a = find(x)
            b = find(y)
            if rank[a] <= rank[b]:
                uf[a] = b
            else:
                uf[b] = a
            if rank[a] == rank[b] and a!=b:
                rank[b]+=1
                
        def find(a):
            if uf[a] == a:
                return a
            else:
                uf[a] = find(uf[a])
                return uf[a]
        
        c = 0
        for i in range(len(strs)):
            for j in range(len(strs)):
                if i != j:
                    if simi(strs[i], strs[j]):
                        #print(strs[i], strs[j], i, j)
                        union(i,j)
        
        #print(uf)
        f = {}
        for i in range(len(uf)):
            f[find(uf[i])] = 1
        return c + len(f)
